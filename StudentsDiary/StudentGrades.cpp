#include"StudentGrades.h"

 StudentGrades::StudentGrades(int gradeid, float math, float bg, float en)
	 : m_gradeid(gradeid)
	 , m_math(math)
	 , m_bg(bg)
	 , m_en(en)
 {
 }

 void StudentGrades::setGradeId(int gradeid)
 {
	 m_gradeid = gradeid;
 }
 
 void StudentGrades::setMath(float math)
 {
	 m_math = math;
 }

 void StudentGrades::setBg(float bg)
 {
	 m_bg = bg;
 }

 void StudentGrades::setEn(float en)
 {
	 m_en = en;
 }
 
 int StudentGrades::getGradeId()
 {
	 return m_gradeid;
 }
 
 int StudentGrades::getGradeId() const
 {
	 return m_gradeid;
 }

 float StudentGrades::getMath()
 {
	 return m_math;
 }

 float StudentGrades::getBg()
 {
	 return m_bg;
 }

 float StudentGrades::getEn()
 {
	 return m_en;
 }