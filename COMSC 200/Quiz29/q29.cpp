/***
 * 
 * The >> operator is overloaded in the istream class. In the iostream library, the base class is ios, which is defined as a virtual class so it can
 * be overloaded. Therefore, ios has no function implementations. istream and ostream both inherit from the ios class. Therefore, the overloaded 
 * operator implementation for >> happens in istream.
 * 
 * ***/

#include <iostream>

using namespace std;

const double DEFAULT_SCORE = 0.0;

class StudentTestScores
{
    private:
        string studentName;
        double * testScores; /// points to array of test scores
        int numTestScore;
    public:
        StudentTestScores(string name, int numScores)
        {
            studentName = name;
            numTestScore = numScores;
            testScores = new double[numTestScore];
            for (int i = 0; i < numTestScore; i++)
            {
                testScores[i] = DEFAULT_SCORE;
            }
        }
        ~StudentTestScores()
        {
            delete [] testScores;
        }
        void setName(string name)
        {
            studentName = name;
            return;
        }
        string getName()
        {
            return studentName;
        }
        void setTestScore(double score, int index)
        {
            testScores[index] = score;
            return;
        }
        double getTestScore(int index)
        {
            return testScores[index];
        }
        void dispalyNameNAllScores()
        {
            cout << getName() << endl;
            for (int i = 0; i < numTestScore; i++)
            {
                cout << getTestScore(i) << " ";
            }
        }
        /// Copy constructor
        /// Enter your code here
        StudentTestScores(const StudentTestScores& st2){
            studentName = st2.studentName;
            numTestScore = st2.numTestScore;
            testScores = new double[numTestScore];
            for(int i = 0; i < numTestScore; i++){
                testScores[i] = st2.testScores[i];
            }
        }
        /// Overloading operator ">"
        /// Enter your code here
        bool operator> (StudentTestScores& st2){
            double avg1 = 0.0;
            double avg2 = 0.0;
            for(int i = 0; i < this->numTestScore; i++){
                avg1 += getTestScore(i);
            }
            avg1 /= this->numTestScore;
            for(int j = 0; j < st2.numTestScore; j++){
                avg2 += st2.getTestScore(j);
            }
            avg2 /= st2.numTestScore;

            return (avg1 > avg2);
        }
};
int main()
{
    StudentTestScores sts1("John", 3);
    sts1.setTestScore(70, 0);
    sts1.setTestScore(80, 1);
    sts1.setTestScore(90, 2);
    cout << endl << "Display 1st student -- 1st run" << endl;
    sts1.dispalyNameNAllScores();
    StudentTestScores sts2 = sts1;
    cout << endl << endl << "Display 2nd student -- 1st run" << endl;
    sts2.dispalyNameNAllScores();
    sts2.setName("Mary");
    sts2.setTestScore(100, 2);
    cout << endl << endl << "The name of 2nd student has been changed to Mary and the 3rd score has been changed to 100.";
    cout << endl << endl << "Display 1st student -- 2nd run" << endl;
    sts1.dispalyNameNAllScores();
    cout << endl << endl << "Display 2nd student -- 2nd run" << endl;
    sts2.dispalyNameNAllScores();
    /// Copy constructor test -- Copy all data in sts1 to sts3
    StudentTestScores sts3(sts1);
    /// Now, let us test again.
    /// Change the third score of sts3 to 99. This should NOT impact the data of sts1
    sts3.setTestScore(99, 2);
    cout << endl << "Display 1st student -- 3rd run" << endl;
    sts1.dispalyNameNAllScores();
    cout << endl << "Display 3rd student -- 3rd run" << endl;
    sts3.dispalyNameNAllScores();
    /// Overloading operator > test
    if (sts2 > sts1)
        cout << "The average score of sts2 is higher than that of sts1" << endl;
    else
        cout << "The average score of sts2 is lower than or equal to that of sts1" << endl;
    return 0;
}