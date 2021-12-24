int calScore(struct Student* stu) {
    int sum = stu->C + stu->English + stu->math;   
    if (stu->C < 60 || stu->math < 60 || stu->English < 60 || sum<=180) {
        stu->grade = 1;     //一定要好好看清题意，180分本身也是不及格
        return 0;
    }
    if (sum > 270) 
        if(stu->C>=90) { stu->grade = 5; return 1; }
        else { stu->grade = 4; return 1; }
    if (sum <= 270 && sum > 240) { stu->grade = 4; return 1; }
    if (sum <= 240 && sum > 210) { stu->grade = 3; return 1; }
    if (sum <= 210 && sum > 180) { stu->grade = 2; return 1; }
}
