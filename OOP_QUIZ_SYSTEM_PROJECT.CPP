#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

//-------------------
//DATA STRUCTURE
//-------------------

struct Question
{   
    string text;
    vector<string> options;
    int correctOptionIndex;
    string difficulty;
};

struct Quiz
{
    string title;
    vector<Question> questions;
};

class Quiz_System
{
private:
    //---------------
    //store data
    //----------------
    string Admin_Username = "c";
    string Admin_Password = "c";
    
    map<string, string> User;
    map<string, string> Participant;
    map<string, vector<pair<string, int>>> UserScores;
    map<string, set<int>> UserTakenQuizzes;
    vector<Quiz> Quizzes = {
        {"General Knowledge", {
            {"Capital of Pakistan?", {"Islamabad", "Karachi", "Lahore", "Peshawar"}, 0, "EASY"},
            {"Largest planet in our solar system?", {"Earth", "Jupiter", "Mars", "Saturn"}, 1, "EASY"}  
        }},
        {"Science", {
            {"What is the chemical symbol for water?", {"H2O", "CO2", "O2", "HO2"}, 0, "EASY"},
            {"How many planets are in the Solar System?", {"7", "8", "9", "10"}, 1, "EASY"},
            {"Who discovered the x-Rays first?",{"Wilhelm Roentgen","Albert Einstein","Isaac Newton","Maryam Nawaz"},0,"MEDIUM"} 
        }},
        {"Math", {
            {"What is 5 + 7?", {"10", "11", "12", "13"}, 2, "EASY"},
            {"What is 15 / 3?", {"3", "4", "5", "6"}, 2, "EASY"},
            {"Derivative Of x?",{"2x","Both C and D","1","x^2"},2,"HARD"}
        }},
        
    };
    

    //---------------
    //REGISTRATION
    //---------------
    
    void Admin_Authentication()
    {   system("cls");
        string Admin_username, Admin_password;
        cout << "Enter username: ";
        cin.ignore();
        cin >> Admin_username;
        cout << "Enter Password: ";
        cin >> Admin_password;
        if (Admin_username == Admin_Username && Admin_password == Admin_Password)
        {
            cout << "Login Done. Press Any key To Enter Admin Menu.";
            getch();
            Admin_Menu();
        }
        else 
        {
            cout << "Wrong Info. Access Denied!\n";
            cout << "Enter\n1)Try Again\n2)Exit.";
            string choice;
            cin >> choice;
              if(choice.length()>1 || !isdigit(choice[0]))
        {
            cout << "Invalid choice! Press any key to try again." << endl;
            getch();
            Admin_Authentication();
        }
            switch (choice[0])
            {
            case '1':
                Admin_Authentication();
                break;
            case '2':
                Run();
                break;
            default:
                cout << "Invalid Option. Press Any key To Return Main Menu.";
                getch();
                Run();
            }
        }
    }

    void User_Registration()
    {   system("cls");
        string User_username, User_password;
        cout << "Enter username: ";
        cin >> User_username;
        cout << "Enter password: ";
        cin >> User_password;
        if (User.find(User_username) == User.end())
        {  
            User[User_username] = User_password;
            cout << "Registered Successfully. Press any key to enter user menu.";
            getch();
            User_UI();
        }
        else 
        {
            cout << "Username Already Used. Press 1)Try Again.\n2)exit.";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                User_Registration();
            }
            else if (choice == 2)
            {
                User_UI();
            }
            else 
            {
                cout << "Invalid Choice! Press Any Key To Return User Menu";
                getch();
                User_UI();
            }
        }
    }

    void User_Authentication()
    {   system("cls");
        string User_username, User_password;
        cout << "Enter username: ";
        cin >> User_username;
        cout << "Enter password: ";
        cin >> User_password;
        if (User.find(User_username) != User.end() && User[User_username] == User_password)
        {
            cout << "Login done. Press any key to enter Quiz menu.";
            getch();
            User_Menu(User_username);
        }
        else 
        {
            cout << "Wrong Credentials. Enter\n1)Try Again.\n2)Exit." << endl;
            string choice;
            cin >> choice;
            if(choice.length()>1 || !isdigit(choice[0]))
        {
            cout << "Invalid choice! Press any key to try again." << endl;
            getch();
            User_Authentication();
        }
            switch (choice[0])
            {
            case '1':
                User_Authentication();
                break;
            case '2':
                User_UI();
                break;
            default:
                cout << "Invalid Option. Press Any key To Exit.";
                getch();
                User_UI();
                break;
            }
        }
    }

    void Participant_Registration()
    {   system("cls");
        string Participant_username, Participant_password;
        cout << "Enter username: ";
        cin >> Participant_username;
        cout << "Enter password: ";
        cin >> Participant_password;
        if (Participant.find(Participant_username) == Participant.end())
        {  
            Participant[Participant_username] = Participant_password;
            cout << "Registered Successfully. Press any key to enter user menu.";
            getch();
            Participant_UI();
        }
        else 
        {
            cout << "Username Already Used. Press 1)Try Again.\n2)exit.";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
               Participant_Registration();
            }
            else if (choice == 2)
            {
                Participant_UI();
            }
            else 
            {
                cout << "Invalid Choice! Press Any Key To Return User Menu";
                getch();
                Participant_UI();
            }
        }
    }

    void Participant_Authentication()
    {   system("cls");
        string Participant_username, Participant_password;
        cout << "Enter username: ";
        cin >> Participant_username;
        cout << "Enter password: ";
        cin >> Participant_password;
        if (Participant.find(Participant_username) != Participant.end() && Participant[Participant_username] == Participant_password)
        {
            cout << "Login done. Press any key to enter Participant menu.\n";
            getch();
            string username;
            cout<<"Enter The userName of Your Child: "<<endl;
            cin>>username;
            Participant_Menu(username);
        }
        else 
        {
            cout << "Wrong Credentials. Enter\n1)Try Again.\n2)Exit." << endl;
            string choice;
            cin >> choice;
               if(choice.length()>1 || !isdigit(choice[0]))
        {
            cout << "Invalid choice! Press any key to try again." << endl;
            getch();
            Participant_Authentication();
        }
            switch (choice[0])
            {
            case '1':
                Participant_Authentication();
                break;
            case '2':
                Participant_UI();
                break;
            default:
                cout << "Invalid Option. Press Any key To Exit.";
                getch();
                Participant_UI();
                break;
            }
        }
    }
   
    //----------------------
    //LOAD INTERFACE
    //---------------------
    void User_UI()
    {   system("cls");
        cout << "Enter\n1)Register.\n2)Login\n3)Exit.";
        string choice;
        cin >> choice;
         if(choice.length()>1 || !isdigit(choice[0]))
        {
            cout << "Invalid choice! Press any key to try again." << endl;
            getch();
            User_UI();
        }
        switch (choice[0])
        {
        case '1':
            User_Registration();
            break;
        case '2':
            User_Authentication();
            break;
        case '3':
            getch();
            Run();
        default:
            cout << "Invalid Choice! Press Any key To Return Main Page.";
            getch();
            Run();
        }
    }

    void Participant_UI()
    {  system("cls");
        cout << "Enter\n1)Register.\n2)Login\n3)Exit.";
        string choice;
        
        cin >> choice;
          if(choice.length()>1 || !isdigit(choice[0]))
        {
            cout << "Invalid choice! Press any key to try again." << endl;
            getch();
            User_UI();
        }
        switch (choice[0])
        {
        case '1':
            Participant_Registration();
            break;
        case '2':
            Participant_Authentication();
            break;
        case '3':
            getch();
            Run();
        default:
            cout << "Invalid Choice! Press Any key To Return Main Page.";
            getch();
            Run();
            break;
        }
    }

    //------------
    //LOAD MENU
    //------------
    void Admin_Menu()
    {   system("cls");
        string choice;
       
    cout << "Choose An Option." << endl;
    cout << "1) Display Quizzes.\n2) Modify Quizzes.\n3) Add Quizzes.\n4) Delete Quiz or Question.\n5) Exit" << endl;
    cin >> choice;
      if(choice.length()>1 || !isdigit(choice[0]))
        {
            cout << "Invalid choice! Press any key to try again." << endl;
            getch();
            Participant_UI();
        }
    switch (choice[0])
    {
    case '1':
        Display_Quizzes();
        break;
    case '2':
        Modify_Quiz();
        break;
    case '3':
        Add_Quizzes();
        break;
    case '4':
        Delete_Quiz_or_Question(Quizzes);
        break;
    case '5':
        Run();
        break;
    default:
        cout << "Invalid Choice! Press Any key To Try Again.";
        getch();
        Admin_Menu();
    }
    }

    void User_Menu(string &username)
    {   system("cls");
        int choice;
        cout << "Choose An Option." << endl;
        cout << "1)Give Quiz.\n2)Show Scores.\n3)Exit." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Give_Quiz(username);
            break;
        case 2:
            View_Scores(username);
            break;
        case 3:
            Run();
            break;
        default:
            cout << "Invalid Choice! Press Any key To Try Again.";
            getch();
            User_Menu(username);
            break;
        }
    }

    void Participant_Menu(string &username)
    {   system("cls");
        string choice;
        
        cout << "Choose An Option." << endl;
        cout << "1)Show Scores of Your Child.\n2)Exit." << endl;
        cin >> choice;
        if(choice.length()>1 || !isdigit(choice[0]))
        {
            cout << "Invalid choice! Press any key to try again." << endl;
            getch();
            Participant_Menu(username);
        }
        switch (choice[0])
        {
        case '1':
            View_Scores(username);
            break;
        case '2':
            Run();
            break;
        default:
            cout << "Invalid Choice! Press Any key To Try Again.";
            getch();
            Participant_Menu(username);
            break;
        }
    }

   

    //---------------------
    //Display Quizzes
    //---------------------
   void Display_Quizzes()
{
    system("cls");
   
    cout << "List of Quizzes" << endl;
    for (size_t i = 0; i < Quizzes.size(); ++i)
    {
        cout << i + 1 << ") " << Quizzes[i].title << endl;
    }

    cout << "Do you want to display questions of a particular quiz?\n";
    cout << "Enter 'Y' to view questions, 'N' to return to the Admin Menu: ";
    char choice;
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        int QuizIndex;
        cout << endl;
        cout << "Enter the quiz number to display questions: ";
        cin >> QuizIndex;

        if (QuizIndex >= 1 && QuizIndex <= Quizzes.size())
        {
            system("cls");
            cout << Quizzes[QuizIndex - 1].title << endl;
            
            for (size_t QuestionNumber=0;QuestionNumber< Quizzes[QuizIndex - 1].questions.size();QuestionNumber++)
            {   const auto &Question=Quizzes[QuizIndex-1].questions[QuestionNumber];
                cout <<QuestionNumber+1<<":"<< Question.text << " [Difficulty: " << Question.difficulty << "]" << endl;
                for (size_t j = 0; j < Question.options.size(); ++j)
                {
                    cout << "    " << char('A' + j) << ") " << Question.options[j] << endl;
                }
            }
        }
        else
        {
            cout << "Invalid quiz number. Press any key to return to the Admin Menu.";
            getch();
            Admin_Menu();
            return;
        }
    }
    else if (choice == 'N' || choice == 'n')
    {
        cout << "Press any key to return to the Admin Menu.";
        getch();
        Admin_Menu();
    }
    else
    {
        cout << "Invalid choice! Press any key to try again.";
        getch();
        Display_Quizzes();
    }

    cout << "Press any key to return to the Admin Menu.";
    getch();
    Admin_Menu();
}


    //---------------------
    //Add Quizzes
    //---------------------
   void Add_Quizzes()
{
    system("cls");
    Quiz newQuiz;
    cout << "Enter the title of the new quiz: ";
    cin.ignore();
    getline(cin, newQuiz.title);

    int questionCount;
    cout << "Enter the number of questions: ";
    while (!(cin >> questionCount) || questionCount <= 0)
    {
        cin.clear(); 
        cin.ignore();
        cout << "Invalid input. Please enter a positive integer for the number of questions: ";
    }

    for (int i = 0; i < questionCount; ++i)
    {
        Question newQuestion;
        cout << "Enter the question text: ";
        cin.ignore();
        getline(cin, newQuestion.text);

        int optionCount;
        cout << "Enter the number of options: ";
        while (!(cin >> optionCount) || optionCount <= 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a positive integer for the number of options: ";
        }

        newQuestion.options.resize(optionCount);
        for (int j = 0; j < optionCount; ++j)
        {
            cout << "Enter option " << char('A' + j) << ": ";
            cin.ignore();
            getline(cin, newQuestion.options[j]);
        }

        cout << "Enter the index of the correct option (0-based): ";
        while (!(cin >> newQuestion.correctOptionIndex) || newQuestion.correctOptionIndex < 0 || newQuestion.correctOptionIndex >= optionCount)
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a valid index for the correct option: ";
        }

        cout << "Enter the difficulty (easy/medium/hard): ";
        cin.ignore();
        getline(cin, newQuestion.difficulty);
        while (newQuestion.difficulty != "easy" && newQuestion.difficulty != "medium" && newQuestion.difficulty != "hard")
        {
            cout << "Invalid input. Please enter 'easy', 'medium', or 'hard' for the difficulty: ";
            getline(cin, newQuestion.difficulty);
        }

        newQuiz.questions.push_back(newQuestion);
    }

    Quizzes.push_back(newQuiz);
    cout << "Quiz added successfully. Press any key to return to the Admin Menu.";
    getch();
    Admin_Menu();
}

    //---------------------
    //Modify Quizzes
    //---------------------
  void Modify_Quiz()
{
    system("cls");
    cout << "List of Quizzes" << endl;
    for (size_t i = 0; i < Quizzes.size(); ++i)
    {
        cout << i + 1 << ") " << Quizzes[i].title << endl;
    }
    int quizIndex;
    cout << "Enter the number of the quiz you want to modify: ";
    cin >> quizIndex;
    quizIndex--;
    if (quizIndex >= Quizzes.size() || quizIndex < 0)
    {
        cout << "Invalid index. Press any key to return to the Admin Menu.";
        getch();
        Admin_Menu();
        return;
    }

    Quiz &quiz = Quizzes[quizIndex];
    cout << "Modifying quiz: " << quiz.title << endl;

    cout << "Choose an option:" << endl;
    cout << "1) Modify Quiz Title." << endl;
    cout << "2) Modify a Specific Question." << endl;
    cout << "3) Modify All Questions in the Quiz." << endl;
    cout << "4) Return to Admin Menu." << endl;
    cout << "Enter your choice: ";
    string choice;
    cin >> choice;
    if (choice.length() > 1 || !isdigit(choice[0]))
    {
        cout << "Invalid Option. Press Any Key To Try Again.";
        getch();
        Modify_Quiz();
        return;
    }

    switch (choice[0])
    {
    case '1':
    {
        cout << "Enter new title for the quiz: ";
        cin.ignore();
        getline(cin, quiz.title);
        cout << "Quiz title modified successfully. Press any key to return to the Admin Menu.";
        getch();
        Admin_Menu();
        break;
    }
    case '2':
    {
        if (quiz.questions.empty())
        {
            cout << "No questions found in this quiz. Press any key to return to the Admin Menu.";
            getch();
            Admin_Menu();
            break;
        }
        system("cls");
        cout << "DISPLAYING QUESTIONS...:\n";
        for (size_t i = 0; i < quiz.questions.size(); ++i)
        {
            cout << i + 1 << ") " << quiz.questions[i].text << endl;
        }
        int questionIndex;
        cout << "Enter the number of the question you want to modify (1-" << quiz.questions.size() << "): ";
        cin >> questionIndex;
        questionIndex--;
        if (questionIndex >= quiz.questions.size() || questionIndex < 0)
        {
            cout << "Invalid index. Press any key to return to the Admin Menu.";
            getch();
            Admin_Menu();
            break;
        }

        Question &question = quiz.questions[questionIndex];
        cout << "Modifying question: " << question.text << endl;
        Modify_Question(question);
        cout << "Question modified successfully. Press any key to return to the Admin Menu.";
        getch();
        Admin_Menu();
        break;
    }
    case '3':
    {
        if (quiz.questions.empty())
        {
            cout << "No questions found in this quiz. Press any key to return to the Admin Menu.";
            getch();
            Admin_Menu();
            break;
        }
        for (size_t i = 0; i < quiz.questions.size(); ++i)
        {
            Question &question = quiz.questions[i];
            cout << "Modifying question " << i + 1 << ": " << question.text << endl;
            Modify_Question(question);
            cout << "Question modified successfully." << endl;
        }
        cout << "All questions in the quiz modified successfully. Press any key to return to the Admin Menu.";
        getch();
        Admin_Menu();
        break;
    }
    case '4':
        Admin_Menu();
        break;
    default:
        cout << "Invalid choice. Press any key to return to the Admin Menu.";
        getch();
        Admin_Menu();
        break;
    }
}


 void Modify_Question(Question &question)
{
    cout << "Enter new text for the question (or press enter to keep the current text): ";
    string newText;
    cin.ignore();
    getline(cin, newText);
    if (!newText.empty())
    {
        question.text = newText;
    }

    for (size_t j = 0; j < question.options.size(); ++j)
    {
        cout << "Enter new text for option " << char('A' + j) << " (or press enter to keep the current text): ";
        string newOptionText;
        getline(cin, newOptionText);
        if (!newOptionText.empty())
        {
            question.options[j] = newOptionText;
        }
    }

    cout << "Enter new correct option index (0-" << question.options.size() - 1 << " or -1 to keep current): ";
    int newCorrectOptionIndex;
    cin >> newCorrectOptionIndex;
    if (newCorrectOptionIndex >= 0 && newCorrectOptionIndex < static_cast<int>(question.options.size()))
    {
        question.correctOptionIndex = newCorrectOptionIndex;
    }

    cout << "Enter new difficulty (EASY, MEDIUM, HARD or press enter to keep current): ";
    cin.ignore();
    string newDifficulty;
    getline(cin, newDifficulty);
    if (!newDifficulty.empty())
    {
        transform(newDifficulty.begin(), newDifficulty.end(), newDifficulty.begin(), ::toupper);
        while (newDifficulty != "EASY" && newDifficulty != "MEDIUM" && newDifficulty != "HARD")
        {
            cout << "Invalid difficulty entered. Please enter EASY, MEDIUM, or HARD: ";
            getline(cin, newDifficulty);
            transform(newDifficulty.begin(), newDifficulty.end(), newDifficulty.begin(), ::toupper);
        }
        question.difficulty = newDifficulty;
    }
}


    //---------------------
    //Delete Quiz or Question
    //---------------------
   void Delete_Quiz_or_Question(vector<Quiz>& Quizzes)
{
    system("cls");
    cout << "List of Quizzes" << endl;
    for (size_t i = 0; i < Quizzes.size(); ++i)
    {
        cout << i + 1 << ") " << Quizzes[i].title << endl;
    }
    int choice;
    cout << "Choose an option:\n1) Delete a quiz.\n2) Delete a question from a quiz.\n3) Exit.\n";
    cin >> choice;

    if (choice == 1)
    {
        int quizIndex;
        cout << "Enter the Number of the quiz to delete: ";
        cin >> quizIndex;
        if (quizIndex < 1 || quizIndex > Quizzes.size())
        {
            cout << "Invalid Number. Press any key to return to the Admin Menu.";
            getch();
            Admin_Menu();
            return;
        }
        Quizzes.erase(Quizzes.begin() + quizIndex - 1);
        cout << "Quiz deleted successfully. Press Any key to return to the Admin Menu.";
    }
    else if (choice == 2)
    {
        int quizIndex;
        cout << "Enter the Number of the quiz: ";
        cin >> quizIndex;
        quizIndex--;
        if (quizIndex >= Quizzes.size())
        {
            cout << "Invalid Number. Press any key to return to the Admin Menu.";
            getch();
            Admin_Menu();
            return;
        }
        Quiz &quiz = Quizzes[quizIndex];

        
        system("cls");
        cout << "Questions of Quiz: " << quiz.title << endl;
        for (size_t i = 0; i < quiz.questions.size(); ++i)
        {
            const Question &question = quiz.questions[i];
            cout << i + 1 << ". " << question.text << " [Difficulty: " << question.difficulty << "]" << endl;
            for (size_t j = 0; j < question.options.size(); ++j)
            {
                cout << "    " << char('A' + j) << ") " << question.options[j] << endl;
            }
            cout << "    Correct Option Index: " << question.correctOptionIndex << endl;
            cout << endl;
        }

        int questionIndex;
        cout << "Enter the Number of the question to delete: ";
        cin >> questionIndex;
        questionIndex--;
        if (questionIndex >= quiz.questions.size())
        {
            cout << "Invalid Number. Press any key to return to the Admin Menu.";
            getch();
            Admin_Menu();
            return;
        }
        quiz.questions.erase(quiz.questions.begin() + questionIndex);
        cout << "Question deleted successfully. Press Any key to return to the Admin Menu.";
    }
    else
    {
        Admin_Menu();
        return;
    }

    getch();
    Admin_Menu();
}


    //---------------------
    //Give Quiz
    //---------------------
  void Give_Quiz(string &username)
{
    system("cls");
    cout << "List of Quizzes" << endl;
    for (size_t i = 0; i < Quizzes.size(); ++i)
    {
        cout << i + 1 << ") " << Quizzes[i].title << endl;
    }

    int quizIndex;
    cout << "Enter the number of the quiz you want to give: ";
    cin >> quizIndex;
    
    if (cin.fail() || quizIndex < 1 || quizIndex > Quizzes.size()) {
        cin.clear(); 
        cin.ignore(); 
        cout << "Invalid index. Press any key to return to the User Menu.";
        getch();
        User_Menu(username);
        return;
    }

    quizIndex--;

    if (UserTakenQuizzes[username].find(quizIndex) != UserTakenQuizzes[username].end()) {
        cout << "You have already taken this quiz. Press any key to return to the User Menu.";
        getch();
        User_Menu(username);
        return;
    }

    const Quiz &quiz = Quizzes[quizIndex];
    int score = 0;
    for (const auto &question : quiz.questions)
    {
        cout << question.text << endl;
        for (size_t i = 0; i < question.options.size(); ++i)
        {
            cout << char('A' + i) << ") " << question.options[i] << endl;
        }
        char answer;
        cout << "Enter your answer (A, B, C, or D): ";
        cin >> answer;
        int answerIndex = toupper(answer) - 'A';
        if (answerIndex == question.correctOptionIndex)
        {
            ++score;
        }
    }

    UserScores[username].push_back(make_pair(quiz.title, score));
    UserTakenQuizzes[username].insert(quizIndex);

    cout << "Quiz completed. Your score: " << score << endl;
    cout << "Press any key to return to the User Menu.";
    getch();
    User_Menu(username);
}


    //---------------------
    //View Scores
    //---------------------
  void View_Scores(string &username)
{
    system("cls");
    cout << "Scores for user: " << username << endl;
    if (UserScores.find(username) != UserScores.end()) {
        for (const auto &entry : UserScores[username]) {
            cout << "Quiz: " << entry.first << " - Score: " << entry.second << endl;
        }
    } else {
        cout << "No scores found for this user." << endl;
    }
    cout << "Press any key to return to the User Menu.";
    getch();
    User_Menu(username);
}

    //---------------------
    //Participants View Scores
    //---------------------
    void view_Scores()
{
    system("cls");
    string childUsername;
    cout << "Enter your child's username: ";
    cin >> childUsername;

    if (UserScores.find(childUsername) == UserScores.end())
    {
        cout << "No scores found for user: " << childUsername << endl;
    }
    else
    {
        cout << "Scores for user: " << childUsername << endl;
        for (const auto &entry : UserScores[childUsername])
        {
            cout << "Quiz: " << entry.first << " - Score: " << entry.second << endl;
        }
    }
    cout << "Press any key to return to the Participant Menu.";
    getch();
    Run();
}

    public:
 
void Run()
{
    system("cls"); 

    string choice;
    cout << "=====================================================" << endl;
    cout << "                  QUIZ SYSTEM                        " << endl;
    cout << "=====================================================" << endl;
    
   
    cout << "=====================================================" << endl;

    cout << setw(15) << left << "1)Admin." << endl;
    cout << setw(15) << left << "2)User." << endl;
    cout << setw(15) << left << "3)Participant." << endl;
    cout << setw(15) << left << "4)Exit." << endl;

    cout << "=====================================================" << endl;
    cout << "Choose An Option: ";
    
    cin >> choice;

    if (choice.length() > 1 || !isdigit(choice[0]))
    {
        cout << "Invalid choice! Press any key to try again." << endl;
        getch();
        Run();
    }

    switch (choice[0])
    {
        case '1':
            cout << "Admin selected." << endl;
            Admin_Authentication();
            break;
        case '2':
            cout << "User selected." << endl;
            User_UI();
            break;
        case '3':
            cout << "Participant selected." << endl;
            Participant_UI();
            break;
        case '4':
            exit(0);
        default:
            cout << "Invalid Choice! Press Any key To Try Again." << endl;
            getch();
            Run();
            break;
    }
}

};

 
    

//---------------------
// Main Function
//---------------------
int main()
{
    Quiz_System system;
    system.Run();
    return 0;
}
