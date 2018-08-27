// Author: Kazon Wilson
// Assignment: Project2

class GradeCalc{
    static void main(String[] args){
        // Read the scores from the file and calculate final grades.
        readFile();
        
        findGrades();

        println();

        System.console().readLine("Press enter to print all student grades. ");

        printAllGrades();    
    }

    static def printAllGrades(){
        printf('%-9s',"C#");
        printf('%-4s',"CLA");
        printf('%-4s',"OLA");
        printf('%-5s',"Quiz");
        printf('%-5s',"Exam");
        printf('%-10s',"FinalExam");
        printf('%-12s',"TotalPoints");
        printf('%-10s',"FinalGrade");
        println();
        for(ID in Global.students){
            printf('%-10s',ID.key);
            printf('%-3s %-4s %-4s %-9s %-11s' + ID.value.totalPoints, ID.value.scores);
            printf('%10s',ID.value.finalGrade);
            println();
        }
    }

    static def findGrades(){
        // Search the grades for each student by their C#.
        def inquiries = 0;
        while (inquiries < 2){
            def studentFound = false;

            def cNum =  System.console().readLine("Please enter the C# you would to search: ");

            for(ID in Global.students){
                if(cNum == ID.key){
                    printf('%-9s',"C#");
                    printf('%-4s',"CLA");
                    printf('%-4s',"OLA");
                    printf('%-5s',"Quiz");
                    printf('%-5s',"Exam");
                    printf('%-10s',"FinalExam");
                    printf('%-12s',"TotalPoints");
                    printf('%-10s',"FinalGrade");
                    println();
                    printf('%-10s',ID.key);
                    printf('%-3s %-4s %-3s %-9s %-11s', ID.value.scores);
                    printf('%-3s',ID.value.totalPoints);
                    printf('%10s',ID.value.finalGrade);
                    println();
                    inquiries++;
                    studentFound = true;
                }
                
            }
            if (!studentFound)
                println("ERROR: The C# you have entered does not exist!");
        
        }
    }

    static def readFile(){
        def fileFound = false;

        while(!fileFound){
            def FILENAME = System.console().readLine("Please enter the file name: ");

            File inFile = new File(FILENAME);

            if(!inFile.exists()){
                println("File does not exist");
            } else {
                fileFound = true;
                def scores = [];
                // Step through each line of the file
                inFile.eachLine { line, number ->
                    // If the line isn't blank
                    if (line.trim()){
                        if (number == 1)
                            return;
                        // Split the line by blank space
                        def tempLine = line.split();
                        // Store all scores in the scores list.
                        for(int i = 1; i<= 5;i++){
                            scores+= tempLine[i];
                        }
                        
                        // Create a student class, with the key being C# and value being the object.
                        Global.students[tempLine[0]] = new Student(tempLine[0], scores);
                        // Calculate the student's grade and store it in the object.
                        Global.students[tempLine[0]].calcGrade();
                        // Reset score list accumulator.
                        scores = [];
                    }
                }
            }
        }
    }
}

class Global{
    static Object students = [:];
}

class Student{
    final def studentID;
    def scores;
    def newScores = [];
    int totalPoints;
    def finalGrade;

    // Constructor for Student class.
    def Student(studentID, scores){
        this.studentID = studentID;
        this.scores = scores;
    }

    def calcGrade(){
        // Convert the scores list from a list of strings to a list of integers
        // and store them in the variable newScores.
        for(String s : scores) newScores.add(Integer.valueOf(s));
        // Calculate the sum of all of scores.
        totalPoints = newScores.sum();
        // Assign final grade based on their total score.
        switch (totalPoints){
            case {it >= 90}:
                finalGrade = "A";
                break;
            case {it >= 87 && it < 90}:
                finalGrade = "B+";
                break;
            case {it >= 83 && it < 87}:
                finalGrade = "B"
                break;
            case {it >= 80 && it < 83}:
                finalGrade = "B-";
                break;
            case {it >= 77 && it < 80}:
                finalGrade = "C+";
                break;
            case {it >= 73 && it < 77}:
                finalGrade = "C";
                break;
            case {it >= 70 && it < 73}:
                finalGrade = "C-";
                break;
            case {it >= 67 && it < 70}:
                finalGrade = "D+";
                break;
            case {it >= 63 && it < 67}:
                finalGrade = "D";
                break;
            case {it >= 60 && it < 63}:
                finalGrade = "D-";
                break;
            default:
                finalGrade = "F";
                break;
        }
    }
}