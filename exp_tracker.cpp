#include <iostream>
#include <vector>


// FUCKING Expense CLASS LIKE A BLUEPRINT  BY USING construct AND GETTER 
class Expense{
  private:
  std::string name;
  double amount;

  public:
  Expense(std::string n , double a) {
    name = n;
    amount = a; }

  std::string getname(){
    return name;
  }


  double getamt(){
    return amount;
  }


  };

// TRAKER classES
class tracker {
  private :
    std::vector<Expense*> exp;
  public:
    void addexpense(std::string names, double amounts){
      Expense* e = new Expense(names,amounts);
      exp.push_back(e);
    }

  void viewexpense(){
    for (int i=0; i < exp.size(); i++) {
     std::cout << exp[i]->getname() << "-->" << exp[i]->getamt() << '\n';
    }
  }
  void viewtotal(){
    double total = 0;
    for(int i=0; i< exp.size();i++){
      total += exp[i]->getamt();
    }
       std::cout << "Total: " << total << '\n';
  } 
    ~tracker(){
      for(int i=0; i < exp.size(); i++){
       delete exp[i];
    }
  }
};

// program starts from here intial point of starting
int main(){
    
    
    std::cout << "**************************EXPENSE-TRACKER";
    std::cout << "**************************" << '\n';
    
   std::cout << "=========================================";
    std::cout << "==========================" << '\n';


tracker t;
int choice;
  
do {
    std::cout << "1-> Add expense" << '\n';
    std::cout << "2-> Showall expensse" << '\n';
    std::cout << "3-> Show total" << '\n';
    std::cout << "4-> Exit" << '\n';
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << '\n';
    
    if(choice == 1) {
        std::string na;
        double am;
        std::cout << "Enter your name: ";
        std::cin >> na;
        std::cout << '\n';
        std::cout << "Enter your amount: ";
        std::cin >> am;
        std::cout << '\n';
        t.addexpense(na,am);
        
    }
    else if (choice == 2) {
        t.viewexpense();
    }    
    else if (choice == 3) {
        t.viewtotal();    
    }
    
    
} while(choice != 4 );
std::cout << "you are exited now" << '\n';



  
}


