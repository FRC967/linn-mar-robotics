package com.example.frcscout3814;

//package com.example.frcscout3814;

//import android.R;
import com.example.frcscout3814.R;
//import your.application.packagename.R;
import android.content.Context;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import java.util.Locale;
import java.util.ResourceBundle;

/**
 * Created by TV Family on 3/8/14.
 */
public class MyPagerAdapter extends PagerAdapter {
    public int getCount(){
        return 5;
    }
    public Object instantiateItem(ViewGroup collection, int position) {
        LayoutInflater inflater = (LayoutInflater) collection.getContext()
                .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        int resId = 0;
        switch (position) {
            case 0:
                resId = R.layout.setup;
                break;
            case 1:
                resId = R.layout.auto;
                break;
            case 2:
                resId = R.layout.teleop;
                break;
            case 3:
                resId = R.layout.comments;
                break;
            case 4:
                resId = R.layout.save;
                break;
        }
        View view = inflater.inflate(resId, null);
        ((ViewPager) collection).addView(view, 0);
        return view;
    }
    @Override
    public void destroyItem(ViewGroup arg0, int arg1, Object arg2) {
        ((ViewPager) arg0).removeView((View) arg2);
    }

    @Override
    public boolean isViewFromObject(View arg0, Object arg1) {
        return arg0 == ((View) arg1);
    }
    
   // private getString getString = new getString();
   public final String getString(int title_section1) { 
	   
	   if(title_section1==2131034116){
		   return "Settings";
	   }
	   else if(title_section1==2131034117){
		   return "Autonomous";
		   
	   }
	   else if(title_section1==2131034118){
		   return "teleop";
	   }   
	   else if(title_section1==2131034119){
		  return "Save";
	   }
		   return Integer.toString(title_section1);
	   }
	   
    
   
   // @Override
   public final CharSequence getPageTitle(int position) {
    	
    	Locale l = Locale.getDefault();
    		switch (position) {
		case 0:
			return getString(R.string.title_section2).toUpperCase(l);
		case 1:
			return getString(R.string.title_section3);//.toUpperCase(1);
		case 2:
			return getString(R.string.title_section4);
		case 3:
			return getString(R.string.title_section5);
		}
    	
 		return null;
	}
	  

    //public boolean isViewFromObject(ViewGroup arg0, Object arg1) {
    // return arg0 == ((View) arg1);
    //}
}
