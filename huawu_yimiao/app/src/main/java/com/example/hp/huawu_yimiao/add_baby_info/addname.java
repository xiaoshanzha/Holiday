package com.example.hp.huawu_yimiao.add_baby_info;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.example.hp.huawu_yimiao.R;
import com.example.hp.huawu_yimiao.db.Baby;

import org.litepal.crud.DataSupport;
import org.litepal.tablemanager.Connector;


public class addname extends AppCompatActivity {

    public String name_text;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_addname);
        Button name_ok = (Button)findViewById(R.id.name_ok);
        final TextView name = (TextView)findViewById(R.id.name);
        final EditText edit = (EditText)findViewById(R.id.edit_name);



        name_ok.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {


                Baby baby0 = DataSupport.findLast(Baby.class);
                String last_sex = baby0.getSex();
                String last_province = baby0.getProvince();
                String last_city = baby0.getCity();
                String last_county = baby0.getCounty();
                int last_year = baby0.getBir_1();
                int last_month = baby0.getBir_2();
                int last_day = baby0.getBir_3();

               name_text = edit.getText().toString();
                Baby baby = new Baby();
                baby.setName(name_text);
                baby.setSex(last_sex);
                baby.setProvince(last_province);
                baby.setCity(last_city);
                baby.setCounty(last_county);
                baby.setBir_1(last_year);
                baby.setBir_2(last_month);
                baby.setBir_3(last_day);
                baby.save();

                Intent intent = new Intent(addname.this,AddBaby.class);
                startActivity(intent);
                finish();


            }

        });

    }
}
