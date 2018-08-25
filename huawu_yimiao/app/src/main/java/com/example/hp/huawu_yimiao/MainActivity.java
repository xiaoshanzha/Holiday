package com.example.hp.huawu_yimiao;

import android.content.Intent;
import android.graphics.ColorSpace;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.EditText;

import com.example.hp.huawu_yimiao.add_baby_info.AddBaby;

import org.litepal.tablemanager.Connector;

import java.util.ArrayList;
import java.util.List;

import de.hdodenhof.circleimageview.CircleImageView;


public class MainActivity extends AppCompatActivity {

    private List<Message> messageList = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar)findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        getSupportActionBar().setDisplayShowTitleEnabled(false);

        CircleImageView img = (CircleImageView)findViewById(R.id.circle_image);
        img.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent intent = new Intent(MainActivity.this,AddBaby.class);
                startActivity(intent);
            }
        });
        final EditText et = (EditText)findViewById(R.id.edit_text);
        et.setCursorVisible(false);
        et.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                et.setCursorVisible(true);
            }
        });

        initMessages();

        RecyclerView recyclerView = (RecyclerView)findViewById(R.id.recycler_view);
        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(layoutManager);

        MessageAdapter adapter = new MessageAdapter(messageList);
        recyclerView.setAdapter(adapter);
    }

    private void initMessages(){

        for(int i = 0;i<3;i++) {
            Message mes_one = new Message(R.drawable.one, R.drawable.two, R.drawable.three, "打百白破出现硬结，正确的处理方式竟然是……", "3022", "1503");
            messageList.add(mes_one);
            Message mes_two = new Message(R.drawable.one1, R.drawable.two1, R.drawable.three1, "疫苗含有无害的死病菌或者是由无害的死病菌中提炼的物质，能使身体产生天然的防御能力对抗病菌。", "4643", "2531");
            messageList.add(mes_two);
            Message mes_three = new Message(R.drawable.one2, R.drawable.two2, R.drawable.three2, "疫苗接种的主要目的是使身体能够制造自然的生物物质，用以提升生物体的对病原的辨认和防御功能。", "653", "321");
            messageList.add(mes_three);
        }

    }
}
