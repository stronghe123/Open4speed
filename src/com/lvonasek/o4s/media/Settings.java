package com.lvonasek.o4s.media;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Point;
import android.util.Log;
import android.view.Display;

/**
 * Created by lubos on 28.10.14.
 */
public class Settings {

    public static final int          MUSIC_VOLUME   = 0;
    public static final int          SOUND_VOLUME   = 1;
    public static final int          VISUAL_QUALITY = 2;

    private static int[]             DEFAULT_VALUES = {100, 100, 100};

    public static void init(Activity instance) {
        Display display = instance.getWindowManager().getDefaultDisplay();
        Point size = new Point();
        display.getSize(size);
        int level = 25 + (int) ((Math.max(size.x, size.y) - 800) / 6.4f);
        level = Math.max(0, Math.min(level, 100));
        DEFAULT_VALUES[VISUAL_QUALITY] = level;
        Log.v("Open4speed", "Default visual quality=" + level);
    }

    public static int getConfig(Context c, int index) {
        SharedPreferences pref = c.getSharedPreferences("MyPref", Context.MODE_PRIVATE);
        return pref.getInt("IntCFG" + index, DEFAULT_VALUES[index]);
    }

    public static void setConfig(Context c, int index, int value) {
        SharedPreferences pref = c.getSharedPreferences("MyPref", Context.MODE_PRIVATE);
        SharedPreferences.Editor edit = pref.edit();
        edit.putInt("IntCFG" + index, value);
        edit.commit();
    }
}