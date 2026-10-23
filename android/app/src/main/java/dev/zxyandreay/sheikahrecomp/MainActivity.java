package dev.zxyandreay.sheikahrecomp;

import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.graphics.Color;
import android.graphics.Typeface;
import android.view.Gravity;
import android.widget.TextView;

public final class MainActivity extends Activity {
    private static boolean nativeReady;
    private static String nativeFailure;
    static {
        try {
            System.loadLibrary("sheikah_bootstrap");
            nativeReady = true;
        } catch (UnsatisfiedLinkError error) {
            nativeFailure = error.toString();
        }
    }
    private static native String nativeDiagnostics();

    @Override public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        String report;
        if (!nativeReady) {
            report = "Native library failed to load:\n" + nativeFailure;
        } else {
            try {
                report = nativeDiagnostics();
            } catch (Throwable error) {
                report = "Native diagnostic failure:\n" + error;
            }
        }
        TextView view = new TextView(this);
        view.setGravity(Gravity.CENTER_VERTICAL);
        view.setPadding(28, 28, 28, 28);
        view.setBackgroundColor(Color.rgb(14, 19, 28));
        view.setTextColor(Color.rgb(220, 232, 242));
        view.setTypeface(Typeface.MONOSPACE);
        view.setTextSize(15);
        view.setText("SheikahRecomp — Android foundation\n\n"
            + report + "\nAndroid API: " + Build.VERSION.SDK_INT
            + "\nDevice ABI: " + java.util.Arrays.toString(Build.SUPPORTED_ABIS)
            + "\n\nNo BOTW game runtime or graphics are integrated.\nNot playable.");
        setContentView(view);
    }
}
