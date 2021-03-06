package org.king.check.domain;



/**
 * ToperlimitId generated by MyEclipse - Hibernate Tools
 */

public class ToperlimitId  implements java.io.Serializable {


    // Fields    

     private String operId;
     private String deptId;


    // Constructors

    /** default constructor */
    public ToperlimitId() {
    }

    

   
    // Property accessors

    public String getOperId() {
        return this.operId;
    }
    
    public void setOperId(String operId) {
        this.operId = operId;
    }

    public String getDeptId() {
        return this.deptId;
    }
    
    public void setDeptId(String deptId) {
        this.deptId = deptId;
    }
   



   public boolean equals(Object other) {
         if ( (this == other ) ) return true;
		 if ( (other == null ) ) return false;
		 if ( !(other instanceof ToperlimitId) ) return false;
		 ToperlimitId castOther = ( ToperlimitId ) other; 
         
		 return ( (this.getOperId()==castOther.getOperId()) || ( this.getOperId()!=null && castOther.getOperId()!=null && this.getOperId().equals(castOther.getOperId()) ) )
 && ( (this.getDeptId()==castOther.getDeptId()) || ( this.getDeptId()!=null && castOther.getDeptId()!=null && this.getDeptId().equals(castOther.getDeptId()) ) );
   }
   
   public int hashCode() {
         int result = 17;
         
         result = 37 * result + ( getOperId() == null ? 0 : this.getOperId().hashCode() );
         result = 37 * result + ( getDeptId() == null ? 0 : this.getDeptId().hashCode() );
         return result;
   }   





}