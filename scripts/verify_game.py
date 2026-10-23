#!/usr/bin/env python3
"""Check only the local RPX SHA-256; do not upload or copy proprietary data."""
import argparse
import hashlib
from pathlib import Path

EXPECTED = "ba58da5b95ce929e005d058ceb08b9b2788d1ab2bbc8a6c189bbadca0bb34d30"

def main():
    parser = argparse.ArgumentParser(description="Validate your own Wii U BOTW USA v208 U-King.rpx")
    parser.add_argument("rpx", type=Path, help="Path to local U-King.rpx")
    args = parser.parse_args()
    if not args.rpx.is_file():
        parser.error("Not a file: " + str(args.rpx))
    digest = hashlib.sha256()
    with args.rpx.open("rb") as handle:
        for chunk in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(chunk)
    current = digest.hexdigest()
    print("SHA-256:", current)
    print("Expected:", EXPECT)
    if current == EXPECT:
        print("Compatible with pinned upstream v208 executable.")
        return 0
    print("Mismatch: do not apply pinned upstream game-specific patches to this executable.")
    return 1

if __name__ == "__main__":
    raise SystemExit(main())
