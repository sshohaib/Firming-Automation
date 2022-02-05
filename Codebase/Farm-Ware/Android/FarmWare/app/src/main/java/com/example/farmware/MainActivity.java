package com.example.farmware;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

import com.google.firebase.auth.FirebaseAuth;

public class MainActivity extends AppCompatActivity {

    private FirebaseAuth firebaseAuth;
   // private Button logout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        firebaseAuth = FirebaseAuth.getInstance();

        //logout = (Button)findViewById(R.id.btnLogout);

        //logout.setOnClickListener(new View.OnClickListener() {
            //@Override
          //  public void onClick(View view) {
            //    Logout();
            //}
        //});
    }

    private void Logout(){
        firebaseAuth.signOut();
        finish();
        startActivity(new Intent(MainActivity.this, LoginActivity.class));
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu){
        getMenuInflater().inflate(R.menu.menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item){
        switch (item.getItemId()){
            case R.id.logoutMenu:{
                Logout();
            }
            case R.id.MyDeviceMenu:{
                startActivity(new Intent(MainActivity.this,MyDeviceActivity.class));
                break;
            }
            case R.id.GoogleMapMenu:{
                startActivity(new Intent(MainActivity.this,MapsActivity.class));
                break;
            }
            case R.id.WeatherMenu:{
                startActivity(new Intent(MainActivity.this,WeatherActivity.class));
                break;
            }
            case R.id.refreshMenu:{
                startActivity(new Intent(MainActivity.this,RefreshActivity.class));
                break;
            }
            case R.id.settingsMenu:{
                startActivity(new Intent(MainActivity.this,RefreshActivity.class));
                break;
            }
        }
        return super.onOptionsItemSelected(item);
    }


}
