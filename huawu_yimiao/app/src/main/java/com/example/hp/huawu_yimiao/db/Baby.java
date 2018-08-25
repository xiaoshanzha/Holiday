package com.example.hp.huawu_yimiao.db;

import org.litepal.crud.DataSupport;

import java.security.PrivateKey;


public    class Baby   extends DataSupport{

    /*
    * 分别记录用户姓名，性别，出生年月日，省市县。
    * */

    private String name;
    private String sex;
    private int Bir_1;
    private int Bir_2;
    private int Bir_3;
    private String province;
    private String city;
    private String county;


    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }



    public String getCounty() {
        return county;
    }

    public void setCounty(String county) {
        this.county = county;
    }

    public String getProvince() {
        return province;
    }

    public void setProvince(String province) {
        this.province = province;
    }



    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }


    public int getBir_1() {
        return Bir_1;
    }

    public void setBir_1(int bir_1) {
        Bir_1 = bir_1;
    }


    public int getBir_2() {
        return Bir_2;
    }

    public void setBir_2(int bir_2) {
        Bir_2 = bir_2;
    }

    public int getBir_3() {
        return Bir_3;
    }

    public void setBir_3(int bir_3) {
        Bir_3 = bir_3;
    }

}
