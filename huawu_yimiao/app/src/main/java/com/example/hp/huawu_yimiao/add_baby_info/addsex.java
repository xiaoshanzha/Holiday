package com.example.hp.huawu_yimiao.add_baby_info;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.example.hp.huawu_yimiao.R;
import com.example.hp.huawu_yimiao.db.Baby;

import org.litepal.crud.DataSupport;
import org.litepal.tablemanager.Connector;

public class addsex extends AppCompatActivity {
    public String sex_text;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_addsex);
        Button sex_ok = (Button)findViewById(R.id.sex_ok);
        final TextView sex = (TextView)findViewById(R.id.sex);
        final EditText edit = (EditText)findViewById(R.id.edit_sex);



        sex_ok.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {


                Baby baby0 = DataSupport.findLast(Baby.class);
                String last_name = baby0.getName();
                String last_province = baby0.getProvince();
                String last_city = baby0.getCity();
                String last_county = baby0.getCounty();
                int last_year = baby0.getBir_1();
                int last_month = baby0.getBir_2();
                int last_day = baby0.getBir_3();


                sex_text = edit.getText().toString();
                int temp= sex_text.compareTo("男");
                int temp1= sex_text.compareTo("女");
                if(temp==0||temp1==0)
                {
                    Baby baby = new Baby();
                    baby.setSex(sex_text);
                    baby.setName(last_name);
                    baby.setProvince(last_province);
                    baby.setCity(last_city);
                    baby.setCounty(last_county);
                    baby.setBir_1(last_year);
                    baby.setBir_2(last_month);
                    baby.setBir_3(last_day);
                    baby.save();

                    Intent intent = new Intent(addsex.this,AddBaby.class);
                    startActivity(intent);
                    finish();
                }
                else{
                    Toast.makeText(getApplicationContext(),"请输入宝宝正确的性别",Toast.LENGTH_SHORT).show();
                }



            }
        });
    }
}
