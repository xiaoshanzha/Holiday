package com.example.hp.huawu_yimiao.db;

import org.litepal.crud.DataSupport;


public class City extends DataSupport {
    private int id;
    private String cityName;
    private int cityCode; //记录市的代号
    private int provinceId; //记录当前市所属省的id

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getProvinceId() {
        return provinceId;
    }

    public void setProvinceId(int provinceId) {
        this.provinceId = provinceId;
    }

    public String getCityName() {
        return cityName;
    }

    public void setCityName(String cityName) {
        this.cityName = cityName;
    }


    public int getCityCode() {
        return cityCode;
    }

    public void setCityCode(int cityCode) {
        this.cityCode = cityCode;
    }

}
