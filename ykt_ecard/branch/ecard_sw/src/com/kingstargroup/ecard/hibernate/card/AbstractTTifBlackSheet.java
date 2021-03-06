/*
 * WARNING: DO NOT EDIT THIS FILE. This is a generated file that is synchronized
 * by MyEclipse Hibernate tool integration.
 *
 * Created Fri Sep 30 14:30:35 CST 2005 by MyEclipse Hibernate Tool.
 */
package com.kingstargroup.ecard.hibernate.card;

import java.io.Serializable;

/**
 * A class that represents a row in the T_TIF_BLACK_SHEET table. 
 * You can customize the behavior of this class by editing the class, {@link TTifBlackSheet()}.
 * WARNING: DO NOT EDIT THIS FILE. This is a generated file that is synchronized * by MyEclipse Hibernate tool integration.
 */
public abstract class AbstractTTifBlackSheet 
    implements Serializable
{
    /** The cached hash code value for this instance.  Settting to 0 triggers re-calculation. */
    private int hashValue = 0;

    /** The composite primary key value. */
    private java.lang.String volume;

    /** The value of the simple cardId property. */
    private java.lang.Integer cardId;

    /** The value of the simple validdate property. */
    private java.lang.String validdate;

    /** The value of the simple stateId property. */
    private java.lang.Integer stateId;

    /** The value of the simple isAd property. */
    private java.lang.Integer isAd;

    /** The value of the simple operateDate property. */
    private java.lang.String operateDate;

    /** The value of the simple operateTime property. */
    private java.lang.String operateTime;

    /** The value of the simple endDate property. */
    private java.lang.String endDate;

    /** The value of the simple endTime property. */
    private java.lang.String endTime;

    /**
     * Simple constructor of AbstractTTifBlackSheet instances.
     */
    public AbstractTTifBlackSheet()
    {
    }

    /**
     * Constructor of AbstractTTifBlackSheet instances given a simple primary key.
     * @param volume
     */
    public AbstractTTifBlackSheet(java.lang.String volume)
    {
        this.setVolume(volume);
    }

    /**
     * Return the simple primary key value that identifies this object.
     * @return java.lang.String
     */
    public java.lang.String getVolume()
    {
        return volume;
    }

    /**
     * Set the simple primary key value that identifies this object.
     * @param volume
     */
    public void setVolume(java.lang.String volume)
    {
        this.hashValue = 0;
        this.volume = volume;
    }

    /**
     * Return the value of the CARD_ID column.
     * @return java.lang.Integer
     */
    public java.lang.Integer getCardId()
    {
        return this.cardId;
    }

    /**
     * Set the value of the CARD_ID column.
     * @param cardId
     */
    public void setCardId(java.lang.Integer cardId)
    {
        this.cardId = cardId;
    }

    /**
     * Return the value of the VALIDDATE column.
     * @return java.lang.String
     */
    public java.lang.String getValiddate()
    {
        return this.validdate;
    }

    /**
     * Set the value of the VALIDDATE column.
     * @param validdate
     */
    public void setValiddate(java.lang.String validdate)
    {
        this.validdate = validdate;
    }

    /**
     * Return the value of the STATE_ID column.
     * @return java.lang.Integer
     */
    public java.lang.Integer getStateId()
    {
        return this.stateId;
    }

    /**
     * Set the value of the STATE_ID column.
     * @param stateId
     */
    public void setStateId(java.lang.Integer stateId)
    {
        this.stateId = stateId;
    }

    /**
     * Return the value of the IS_AD column.
     * @return java.lang.Integer
     */
    public java.lang.Integer getIsAd()
    {
        return this.isAd;
    }

    /**
     * Set the value of the IS_AD column.
     * @param isAd
     */
    public void setIsAd(java.lang.Integer isAd)
    {
        this.isAd = isAd;
    }

    /**
     * Return the value of the OPERATE_DATE column.
     * @return java.lang.String
     */
    public java.lang.String getOperateDate()
    {
        return this.operateDate;
    }

    /**
     * Set the value of the OPERATE_DATE column.
     * @param operateDate
     */
    public void setOperateDate(java.lang.String operateDate)
    {
        this.operateDate = operateDate;
    }

    /**
     * Return the value of the OPERATE_TIME column.
     * @return java.lang.String
     */
    public java.lang.String getOperateTime()
    {
        return this.operateTime;
    }

    /**
     * Set the value of the OPERATE_TIME column.
     * @param operateTime
     */
    public void setOperateTime(java.lang.String operateTime)
    {
        this.operateTime = operateTime;
    }

    /**
     * Return the value of the END_DATE column.
     * @return java.lang.String
     */
    public java.lang.String getEndDate()
    {
        return this.endDate;
    }

    /**
     * Set the value of the END_DATE column.
     * @param endDate
     */
    public void setEndDate(java.lang.String endDate)
    {
        this.endDate = endDate;
    }

    /**
     * Return the value of the END_TIME column.
     * @return java.lang.String
     */
    public java.lang.String getEndTime()
    {
        return this.endTime;
    }

    /**
     * Set the value of the END_TIME column.
     * @param endTime
     */
    public void setEndTime(java.lang.String endTime)
    {
        this.endTime = endTime;
    }

    /**
     * Implementation of the equals comparison on the basis of equality of the primary key values.
     * @param rhs
     * @return boolean
     */
    public boolean equals(Object rhs)
    {
        if (rhs == null)
            return false;
        if (! (rhs instanceof TTifBlackSheet))
            return false;
        TTifBlackSheet that = (TTifBlackSheet) rhs;
        if (this.getVolume() == null || that.getVolume() == null)
            return false;
        return (this.getVolume().equals(that.getVolume()));
    }

    /**
     * Implementation of the hashCode method conforming to the Bloch pattern with
     * the exception of array properties (these are very unlikely primary key types).
     * @return int
     */
    public int hashCode()
    {
        if (this.hashValue == 0)
        {
            int result = 17;
            int volumeValue = this.getVolume() == null ? 0 : this.getVolume().hashCode();
            result = result * 37 + volumeValue;
            this.hashValue = result;
        }
        return this.hashValue;
    }
}
