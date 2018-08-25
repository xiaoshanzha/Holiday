package com.example.hp.huawu_yimiao.add_baby_info;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.example.hp.huawu_yimiao.AreaActivity;
import com.example.hp.huawu_yimiao.MainActivity;
import com.example.hp.huawu_yimiao.R;
import com.example.hp.huawu_yimiao.db.Baby;

import org.litepal.crud.DataSupport;
import org.litepal.tablemanager.Connector;

import java.util.List;


public class AddBaby extends AppCompatActivity {

    private String data_name;
    private String data_sex;
    private String data_birth;
    private String data_place;



    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_baby);
        TextView name = (TextView)findViewById(R.id.name);
        TextView sex = (TextView)findViewById(R.id.sex);
        TextView birth = (TextView)findViewById(R.id.birth);
        TextView location = (TextView)findViewById(R.id.location);
        Button ok = (Button)findViewById(R.id.add_ok);


        Connector.getDatabase();//创建数据库


       Baby baby = DataSupport.findLast(Baby.class);
            data_name = baby.getName();
            data_sex = baby.getSex();
            data_place = baby.getProvince()+"、"+baby.getCity()+"、"+baby.getCounty();
            data_birth = baby.getBir_1()+"、"+baby.getBir_2()+"、"+baby.getBir_3();
        name.setText(data_name);
        sex.setText(data_sex);
        location.setText(data_place);
        birth.setText(data_birth);


        name.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(AddBaby.this,addname.class);
                startActivity(intent);
                finish();
            }
        });
        sex.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(AddBaby.this,addsex.class);
                startActivity(intent);
                finish();
            }
        });
        location.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(AddBaby.this,AreaActivity.class);
                startActivity(intent);
                finish();
            }
        });
        birth.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(AddBaby.this, addbirth.class);
                startActivity(intent);
                finish();
            }
        });
        ok.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(AddBaby.this, MainActivity.class);
                startActivity(intent);
                finish();
            }
        });
    }
}
