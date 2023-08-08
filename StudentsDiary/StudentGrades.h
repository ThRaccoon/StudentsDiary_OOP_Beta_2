#pragma once
#include <string> 

class StudentGrades
{
	public:
		StudentGrades() = default;
		StudentGrades(int gradeid, float math, float bg, float en);

		void setGradeId(int gradeid);
		void setMath(float math);
		void setBg(float bg);
		void setEn(float en);
		 
		int getGradeId();
		int getGradeId() const;
		float getMath();
		float getBg();
		float getEn();
		 
	private:
		int m_gradeid;
		float m_math;
		float m_bg;
		float m_en;
};