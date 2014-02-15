package com.example.frcgame;



import java.io.*;

import android.R.color;
import android.os.Bundle;
import android.os.Environment;
import android.app.Activity;
import android.content.Context;
import android.view.Menu;
import android.view.View;
import android.widget.*;
//ColorChangeButtons as per http://stackoverflow.com/questions/1521640/standard-android-button-with-a-different-color?
//import android.graphics.PorterDuff; 

public class MainActivity extends Activity {


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
				objectStorage.txtpass.append("ID,Alliance,Time,TeamNumber,MatchID");
				//final StringBuilder txtpass = new StringBuilder();                                              
				// {{ CheckBoxes
				final CheckBox doubleauto = (CheckBox) findViewById(R.id.dAuto);
				final CheckBox automobonus = (CheckBox) findViewById(R.id.Mobility_Bonus);
				final CheckBox telemobonus = (CheckBox) findViewById(R.id.Mobility_Bonus_T);
				final CheckBox hotGoal = (CheckBox) findViewById(R.id.Hot_Goals);
				final CheckBox autoBonus = (CheckBox) findViewById(R.id.Auto_Bonus);
				final CheckBox autofoul = (CheckBox) findViewById(R.id.Foul);
				final CheckBox telefoul = (CheckBox) findViewById(R.id.Foul_T);
				final CheckBox teletechfoul = (CheckBox) findViewById(R.id.Tech_Foul_T);
				final CheckBox truss = (CheckBox) findViewById(R.id.Truss);
				final CheckBox twoassist = (CheckBox) findViewById(R.id.two_assist);
				final CheckBox threeassist = (CheckBox) findViewById(R.id.three_assist);
				final CheckBox autotechfoul = (CheckBox) findViewById(R.id.Tech_Foul);
				final CheckBox autoshotblock = (CheckBox) findViewById(R.id.Blocked_Shots);
				final CheckBox teleshotblock = (CheckBox) findViewById(R.id.Blocked_Shots_T);
				final CheckBox automechprob = (CheckBox) findViewById(R.id.Mechanical_Problems);
				final CheckBox telemechprob = (CheckBox) findViewById(R.id.Mechanical_Problems);
				// }} CheckBoxes
		 		// {{ Number Picker
				//  Number Picker Initialization
		      	NumberPicker nplg = (NumberPicker) findViewById(R.id.Low_Goal);
		        nplg.setMaxValue(100);
		        nplg.setMinValue(0);
		        NumberPicker nphg = (NumberPicker) findViewById(R.id.High_Goal);
		        nphg.setMaxValue(100);
		        nphg.setMinValue(0);
		        NumberPicker npc = (NumberPicker) findViewById(R.id.Catches);
		        npc.setMaxValue(100);
		        npc.setMinValue(0);
		        // }} Number Picker
		        //MainActivity.context = getApplicationContext();
		        // {{ Radio Button
		        final RadioGroup allianceradio = (RadioGroup) findViewById(R.id.radioGroup1);
		        final RadioButton radiored= (RadioButton) findViewById(R.id.radioRed);
		        final RadioButton radioblue = (RadioButton) findViewById(R.id.radioBlue);
		        final Button submitAlliance = (Button) findViewById(R.id.submitAlliance);
		        submitAlliance.setOnClickListener(new View.OnClickListener() {	
					@Override
					public void onClick(View v) {
						// TODO Auto-generated method stub
						if((RadioButton) findViewById(allianceradio.getCheckedRadioButtonId())==radiored){
							objectStorage.alliance="R";
							submitAlliance.setEnabled(false);
						}
						if((RadioButton) findViewById(allianceradio.getCheckedRadioButtonId())==radioblue){
							objectStorage.alliance="B";
							submitAlliance.setEnabled(false);
						}
					}
				});
		        // }} Radio Button
		        // {{ Comments
		        //Comments on Tele
		        	final EditText telecomm = (EditText) findViewById(R.id.Comments_Tele);
		        //Comments on Auto
		        	final EditText autocomm = (EditText) findViewById(R.id.Comments_Auto);
		        //These are objects that can be used to get and set text ie. autocomm.setText("Hello")
		        	final EditText teamnumber = (EditText) findViewById(R.id.TeamNo);
		        	final EditText matchId = (EditText) findViewById(R.id.matchId);
		        // }} Comments
		      	// {{ Button Init
		        		//Shot
		        	final Button shot = (Button) findViewById(R.id.Shot);
		        	
		        shot.setOnClickListener(new View.OnClickListener() {
					
					@Override
					public void onClick(View v) {
						// TODO Auto-generated method stub
						objectStorage.txtpass.append("\n"+"S"+","+objectStorage.alliance+","+System.currentTimeMillis()+","+teamnumber.getText()+","+matchId.getText());
					}
				});
		        		//received
		        	final Button received = (Button) findViewById(R.id.Recieved);
		        	
		        received.setOnClickListener(new View.OnClickListener() {
					
					@Override
					public void onClick(View v) {
						// TODO Auto-generated method stub
						objectStorage.txtpass.append("\n"+"R"+","+objectStorage.alliance+","+System.currentTimeMillis()+","+teamnumber.getText()+","+matchId.getText());
					}
				});
		        		//Passed
		        	final Button passed = (Button) findViewById(R.id.Passed);
		        	
		        passed.setOnClickListener(new View.OnClickListener() {
					
					@Override
					public void onClick(View v) {
						// TODO Auto-generated method stub
						objectStorage.txtpass.append("\n"+"P"+","+objectStorage.alliance+","+System.currentTimeMillis()+","+teamnumber.getText()+","+matchId.getText());
					}
				});
		        		//BL
		        	final Button balllosspass = (Button) findViewById(R.id.missedPass);
		        	
		        balllosspass.setOnClickListener(new View.OnClickListener() {
					
					@Override
					public void onClick(View v) {
						// TODO Auto-generated method stub
						objectStorage.txtpass.append("\n"+"BL"+","+objectStorage.alliance+","+System.currentTimeMillis()+","+teamnumber.getText()+","+matchId.getText());
					}
				});
		        	final Button balllossshot = (Button) findViewById(R.id.missedShot);
		        	
		        balllossshot.setOnClickListener(new View.OnClickListener() {
					
					@Override
					public void onClick(View v) {
						// TODO Auto-generated method stub
						objectStorage.txtpass.append("\n"+"BL"+","+objectStorage.alliance+","+System.currentTimeMillis()+","+teamnumber.getText()+","+matchId.getText());
					}
				});
		        // }} Button Init
		        //Send Data Button initialization
		        final Button datasend = (Button) findViewById(R.id.senddata);
		        datasend.setOnClickListener(new View.OnClickListener() {
					@Override
					public void onClick(View v) {
						// TODO Auto-generated method stub
						//Enter Send Data Code Here
						Toast.makeText(MainActivity.this, "Data Sent"+objectStorage.txtpass.toString(), 100).show();
							//File file = new File(Environment.getExternalStorageDirectory().toString()+"/FRCGameScout","passdata"+matchId.getText()+teamnumber.getText()+".csv");
						//Write file
						try{
							String extdirpath = Environment.getExternalStorageDirectory().toString()+"/FRCGameData";
							String intdirpath = Environment.getExternalStorageDirectory().toString()+"/FRCGameData/PassData";
							File intdirfile = new File(extdirpath,"PassData");
							if(!intdirfile.exists()){
								intdirfile.mkdirs();
							}
							File realfilepass = new File(intdirpath,"passdata"+" "+matchId.getText()+" "+teamnumber.getText()+".csv");
							if(!realfilepass.exists()){
								objectStorage.outputStream = new FileOutputStream(realfilepass,false);
								objectStorage.outputStreamWriter = new OutputStreamWriter(objectStorage.outputStream);
							}
							else{
								objectStorage.outputStream = new FileOutputStream(realfilepass,true);
								objectStorage.outputStreamWriter = new OutputStreamWriter(objectStorage.outputStream);
							}
							objectStorage.outputStreamWriter.write(objectStorage.txtpass.toString());
							objectStorage.outputStream.write(String.valueOf(objectStorage.txtpass).getBytes());
						}
						catch(Exception e){
							//If there is an exception, I give up.
						}
					}
				});
	}

	
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
}
//