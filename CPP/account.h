class Account {
private:
    string number;
    string name;
    int balance;
public:
    Account(string num, string nm, int bal);
    int deposit(int money);
    int withdraw(int money);
    int addInterest();
    void display();
}