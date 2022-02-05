package com.example.farmware;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MyDeviceActivity extends AppCompatActivity {

    TextView a,b,c,d,e,f,g;
    Button btn;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_my_device);

        a=(TextView)findViewById(R.id.tvRd);
        b=(TextView)findViewById(R.id.tvTemp);
        c=(TextView)findViewById(R.id.tvHumi);
        d=(TextView)findViewById(R.id.tvSm);
        e=(TextView)findViewById(R.id.tvWl);
        f=(TextView)findViewById(R.id.tvWv);
        g=(TextView)findViewById(R.id.tvTotal);
        btn=(Button)findViewById(R.id.btn) ;

        //logout = (Button)findViewById(R.id.btnLogout);

        //logout.setOnClickListener(new View.OnClickListener() {
        //@Override
        //  public void onClick(View view) {
        //    Logout();
        //}
        //});
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MyDeviceActivity.this, RefreshActivity.class));

            }
        });
    }
}
