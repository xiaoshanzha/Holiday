package com.example.hp.huawu_yimiao;



public class Message {
    private String text;
    private String see_num;
    private String pinglun_num;
    private  int imageId1;
    private  int imageId2;
    private  int imageId3;

    public  Message(int imageId1,int imageId2,int imageId3,String text,String see_num,String pinglun_num)
    {
        this.imageId1 = imageId1;
        this.imageId2 = imageId2;
        this.imageId3 = imageId3;
        this.pinglun_num = pinglun_num;
        this.see_num = see_num;
        this.text = text;
    }
    public  String getText(){
        return text;
    }
    public  String getSee_num(){
        return see_num;
    }
    public  String getPinglun_num(){
        return pinglun_num;
    }

    public  int getImageId1(){
        return imageId1;
    }

    public  int getImageId2(){
        return imageId2;
    }
    public  int getImageId3(){
        return imageId3;
    }
}
