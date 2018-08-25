package com.example.hp.huawu_yimiao;

import android.app.Notification;
import android.content.Intent;
import android.net.Uri;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.List;

/**
 * Created by HP on 2018/8/19.
 */

public    class MessageAdapter extends RecyclerView.Adapter<MessageAdapter.ViewHolder> {

    private List<Message> mMessage;

    public class ViewHolder extends RecyclerView.ViewHolder {

        View messageView;
        ImageView one;
        ImageView two;
        ImageView three;
        TextView text;
        TextView see;
        TextView pinglun;

        public  ViewHolder(View view){
            super(view);
            messageView = view;
            one = (ImageView)view.findViewById(R.id.img1);
            two = (ImageView)view.findViewById(R.id.img2);
            three = (ImageView)view.findViewById(R.id.img3);
            text = (TextView)view.findViewById(R.id.text);
            pinglun = (TextView)view.findViewById(R.id.ping_num);
            see = (TextView)view.findViewById(R.id.see_num);
        }
    }

    public MessageAdapter(List<Message> messageList){
        mMessage = messageList;
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.activity_message,parent,false);
        final  ViewHolder holder = new ViewHolder(view);

        //Recyclerview子项的点击事件
        holder.one.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int position = holder.getAdapterPosition();
                Message message = mMessage.get(position);
                Intent intent = new Intent(Intent.ACTION_VIEW);
                intent.setData(Uri.parse("http://www.baidu.com"));
                v.getContext().startActivity(intent);
            }
        });
        holder.two.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int position = holder.getAdapterPosition();
                Message message = mMessage.get(position);
                Intent intent = new Intent(Intent.ACTION_VIEW);
                intent.setData(Uri.parse("http://z.yeemiao.com/mm/api/share/article-detail-1702?t=13973584&platform=2&source=shared&share=1"));
                v.getContext().startActivity(intent);
            }
        });
        holder.three.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int position = holder.getAdapterPosition();
                Message message = mMessage.get(position);
                Intent intent = new Intent(Intent.ACTION_VIEW);
                intent.setData(Uri.parse("http://z.yeemiao.com/mm/api/share/article-detail-1702?t=13973584&platform=2&source=shared&share=1"));
                v.getContext().startActivity(intent);
            }
        });
        holder.text.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int position = holder.getAdapterPosition();
                Message message = mMessage.get(position);
                Intent intent = new Intent(Intent.ACTION_VIEW);
                intent.setData(Uri.parse("http://z.yeemiao.com/mm/api/share/article-detail-1702?t=13973584&platform=2&source=shared&share=1"));
                v.getContext().startActivity(intent);
            }
        });



        return holder;
    }


    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        Message message = mMessage.get(position);
        holder.one.setImageResource(message.getImageId1());
        holder.two.setImageResource(message.getImageId2());
        holder.three.setImageResource(message.getImageId3());
        holder.text.setText(message.getText());
        holder.pinglun.setText(message.getPinglun_num());
        holder.see.setText(message.getSee_num());
    }

    @Override
    public int getItemCount(){
        return  mMessage.size();
    }

}


