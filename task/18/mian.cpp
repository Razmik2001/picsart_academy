#include <iostream>
#include "sys.hpp"

int main()
{
    User user1("John", "john@email.com", { "C++", "Python", "Problem Solving" });
    Job job1("Software Developer", "Developing web applications", { "C++", "JavaScript", "HTML", "CSS" }, "Tech Company", 60000);
    Job job2("Data Analyst", "Analyzing and interpreting data", { "Python", "Data Analysis", "Statistics" }, "Data Corp", 55000);
    Job job3("Java Developer", "Backend development", { "Java", "Spring Boot", "SQL" }, "Tech Startup", 58000);
    sys jobMatchingSystem;
    jobMatchingSystem.addUser(&user1);
    jobMatchingSystem.addJob(&job1);
    jobMatchingSystem.addJob(&job2);
    jobMatchingSystem.addJob(&job3);
    jobMatchingSystem.find(1, user1.getReq());
    jobMatchingSystem.find(1, "Software Developer");
    jobMatchingSystem.find(1, 56000);
    return 0;
}