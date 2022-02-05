package com.example.farmware;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.icu.text.SimpleDateFormat;
import android.os.Bundle;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.Calendar;

public class WeatherActivity extends AppCompatActivity {

    TextView t1_temp,t2_city,t3_description,t4_date,t5_c;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_weather);

        t1_temp = (TextView)findViewById(R.id.textView3);
        t2_city = (TextView)findViewById(R.id.textView4);
        t3_description = (TextView)findViewById(R.id.textView6);
        t4_date = (TextView)findViewById(R.id.textView2);
        t5_c = (TextView)findViewById(R.id.textView5);

        t1_temp.setTextColor(Color.WHITE);
        t1_temp.setTextSize(40);

        t2_city.setTextColor(Color.WHITE);
        t2_city.setTextSize(20);

        t3_description.setTextColor(Color.WHITE);
        t3_description.setTextSize(20);

        t4_date.setTextColor(Color.WHITE);
        t4_date.setTextSize(20);

        t5_c.setTextColor(Color.WHITE);
        t5_c.setTextSize(10);

        find_weather();

    }

    public void find_weather(){
        String url = "http://api.openweathermap.org/data/2.5/weather?q=Dhaka,Bangladesh&appid=1b95532291dc4b4762d0e3a954e1db96&units=imperial";
        JsonObjectRequest jor = new JsonObjectRequest(Request.Method.GET, url, null, new Response.Listener<JSONObject>() {
            @Override
            public void onResponse(JSONObject response) {
                try{
                    JSONObject main_object = response.getJSONObject("main");
                    JSONArray array = response.getJSONArray("weather");
                    JSONObject object = array.getJSONObject(0);
                    String temp = String.valueOf(main_object.getDouble("temp"));
                    String description = object.getString("description");
                    String city = response.getString("name");


                    //t1_temp.setText(temp);
                    t2_city.setText(city);
                    t3_description.setText(description);

                    Calendar calendar = Calendar.getInstance();
                    SimpleDateFormat sdf = new SimpleDateFormat("YYYY-MM-DD");
                    String formatted_date = sdf.format(calendar.getTime());

                    t4_date.setText(formatted_date);

                    double temp_int = Double.parseDouble(temp);
                    double centi = (temp_int-32)/1.800;
                    centi = Math.round(centi);
                    int i = (int) centi;
                    t1_temp.setText(String.valueOf(i));

                }catch (JSONException e){
                    e.printStackTrace();
                }
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {

            }
        }
        );
        RequestQueue queue = Volley.newRequestQueue(this);
        queue.add(jor);
    }
}
