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

public class addbirth extends AppCompatActivity {


    public int year1;

    public int month1;
   public int day1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_addbirth);
        final EditText year = (EditText)findViewById(R.id.edit1);
        final EditText month = (EditText)findViewById(R.id.edit2);
        final EditText day = (EditText)findViewById(R.id.edit3);
        Button birth_ok = (Button)findViewById(R.id.birth_ok);



        birth_ok.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                year1 = Integer.parseInt(year.getText().toString());
                month1 = Integer.parseInt(month.getText().toString());
                day1 = Integer.parseInt(day.getText().toString());

                if(year1>=1900&&year1<2019&&0<month1&&month1<13&&day1>0&&day1<32)
                {
                    if((month1==2||month1==4||month1==6||month1==9||month1==11)&&day1==31)
                    {
                        Toast.makeText(getApplicationContext(),"请输入宝宝正确的出生日",Toast.LENGTH_SHORT).show();
                    }
                    else
                    {
                        Baby baby0 = DataSupport.findLast(Baby.class);
                        String last_sex = baby0.getSex();
                        String last_province = baby0.getProvince();
                        String last_city = baby0.getCity();
                        String last_county = baby0.getCounty();
                        String last_name = baby0.getName();



                        Baby baby = new Baby();
                        baby.setBir_1(year1);
                        baby.setBir_2(month1);
                        baby.setBir_3(day1);

                        baby.setSex(last_sex);
                        baby.setProvince(last_province);
                        baby.setCity(last_city);
                        baby.setCounty(last_county);
                        baby.setName(last_name);
                        baby.save();

                        Intent intent = new Intent(addbirth.this,AddBaby.class);
                        startActivity(intent);
                        finish();
                    }

                }
                else{
                    Toast.makeText(getApplicationContext(),"请输入宝宝正确的出生日",Toast.LENGTH_SHORT).show();
                }

            }
        });
    }
}
