package org.king.classmanage.domain;

import java.util.Date;


/**
 * AbstractGzDormApply generated by MyEclipse - Hibernate Tools
 */

public abstract class AbstractGzDormApply extends org.king.framework.domain.BaseObject implements java.io.Serializable {


    // Fields    

     private String id;
     private String studentNo;
     private String enrollNo;
     private String district;
     private String curAddress;
     private String curTelephone;
     private String ifNeedDorm;
     private String ifGiveDorm;
     private String memo;
     private String updator;
     private Date updateTime;


    // Constructors

    /** default constructor */
    public AbstractGzDormApply() {
    }

    
    /** full constructor */
    public AbstractGzDormApply(String studentNo, String enrollNo, String district, String curAddress, String curTelephone, String ifNeedDorm, String ifGiveDorm, String memo, String updator, Date updateTime) {
        this.studentNo = studentNo;
        this.enrollNo = enrollNo;
        this.district = district;
        this.curAddress = curAddress;
        this.curTelephone = curTelephone;
        this.ifNeedDorm = ifNeedDorm;
        this.ifGiveDorm = ifGiveDorm;
        this.memo = memo;
        this.updator = updator;
        this.updateTime = updateTime;
    }

   
    // Property accessors

    public String getId() {
        return this.id;
    }
    
    public void setId(String id) {
        this.id = id;
    }

    public String getStudentNo() {
        return this.studentNo;
    }
    
    public void setStudentNo(String studentNo) {
        this.studentNo = studentNo;
    }

    public String getEnrollNo() {
        return this.enrollNo;
    }
    
    public void setEnrollNo(String enrollNo) {
        this.enrollNo = enrollNo;
    }

    public String getDistrict() {
        return this.district;
    }
    
    public void setDistrict(String district) {
        this.district = district;
    }

    public String getCurAddress() {
        return this.curAddress;
    }
    
    public void setCurAddress(String curAddress) {
        this.curAddress = curAddress;
    }

    public String getCurTelephone() {
        return this.curTelephone;
    }
    
    public void setCurTelephone(String curTelephone) {
        this.curTelephone = curTelephone;
    }

    public String getIfNeedDorm() {
        return this.ifNeedDorm;
    }
    
    public void setIfNeedDorm(String ifNeedDorm) {
        this.ifNeedDorm = ifNeedDorm;
    }

    public String getIfGiveDorm() {
        return this.ifGiveDorm;
    }
    
    public void setIfGiveDorm(String ifGiveDorm) {
        this.ifGiveDorm = ifGiveDorm;
    }

    public String getMemo() {
        return this.memo;
    }
    
    public void setMemo(String memo) {
        this.memo = memo;
    }

    public String getUpdator() {
        return this.updator;
    }
    
    public void setUpdator(String updator) {
        this.updator = updator;
    }

    public Date getUpdateTime() {
        return this.updateTime;
    }
    
    public void setUpdateTime(Date updateTime) {
        this.updateTime = updateTime;
    }
   








}