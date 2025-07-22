// Link: https://leetcode.com/problems/design-an-atm-machine/description
// Description
// There is an ATM machine that stores banknotes of
// 5
// denominations:
// 20
// ,
// 50
// ,
// 100
// ,
// 200
// , and
// 500
// dollars. Initially the ATM is empty. The user can use the machine to deposit or withdraw any amount of money.
// When withdrawing, the machine prioritizes using banknotes of
// larger
// values.
// For example, if you want to withdraw
// $300
// and there are
// 2
// $50
// banknotes,
// 1
// $100
// banknote, and
// 1
// $200
// banknote, then the machine will use the
// $100
// and
// $200
// banknotes.
// However, if you try to withdraw
// $600
// and there are
// 3
// $200
// banknotes and
// 1
// $500
// banknote, then the withdraw request will be rejected because the machine will first try to use the
// $500
// banknote and then be unable to use banknotes to complete the remaining
// $100
// . Note that the machine is
// not
// allowed to use the
// $200
// banknotes instead of the
// $500
// banknote.
// Implement the ATM class:
// ATM()
// Initializes the ATM object.
// void deposit(int[] banknotesCount)
// Deposits new banknotes in the order
// $20
// ,
// $50
// ,
// $100
// ,
// $200
// , and
// $500
// .
// int[] withdraw(int amount)
// Returns an array of length
// 5
// of the number of banknotes that will be handed to the user in the order
// $20
// ,
// $50
// ,
// $100
// ,
// $200
// , and
// $500
// , and update the number of banknotes in the ATM after withdrawing. Returns
// [-1]
// if it is not possible (do
// not
// withdraw any banknotes in this case).
// Example 1:
// Input
// ["ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"]
// [[], [[0,0,1,2,1]], [600], [[0,1,0,1,1]], [600], [550]]
// Output
// [null, null, [0,0,1,0,1], null, [-1], [0,1,0,0,1]]
// Explanation
// ATM atm = new ATM();
// atm.deposit([0,0,1,2,1]); // Deposits 1 $100 banknote, 2 $200 banknotes,
//                           // and 1 $500 banknote.
// atm.withdraw(600);        // Returns [0,0,1,0,1]. The machine uses 1 $100 banknote
//                           // and 1 $500 banknote. The banknotes left over in the
//                           // machine are [0,0,0,2,0].
// atm.deposit([0,1,0,1,1]); // Deposits 1 $50, $200, and $500 banknote.
//                           // The banknotes in the machine are now [0,1,0,3,1].
// atm.withdraw(600);        // Returns [-1]. The machine will try to use a $500 banknote
//                           // and then be unable to complete the remaining $100,
//                           // so the withdraw request will be rejected.
//                           // Since the request is rejected, the number of banknotes
//                           // in the machine is not modified.
// atm.withdraw(550);        // Returns [0,1,0,0,1]. The machine uses 1 $50 banknote
//                           // and 1 $500 banknote.
// Constraints:
// banknotesCount.length == 5
// 0 <= banknotesCount[i] <= 10
// 9
// 1 <= amount <= 10
// 9
// At most
// 5000
// calls
// in total
// will be made to
// withdraw
// and
// deposit
// .
// At least
// one
// call will be made to each function
// withdraw
// and
// deposit
// .
// Sum of
// banknotesCount[i]
// in all deposits doesn't exceed
// 10
// 9

class Bundle{
public:
    Bundle(){
        mp[20] = 0;
        mp[50] = 1;
        mp[100] = 2;
        mp[200] = 3;
        mp[500] = 4;
    }
    virtual bool withdraw(int amount, vector<int> &notes) = 0;
    virtual void deposit(const vector<int> &banknotesCount) = 0;

    bool withdraw_helper(int &amount, const int note_value, int &note_count, Bundle *nextBundle, vector<int> &notes){
        if(amount == 0){
            return true;            
        }

        int notes_can_use = min(amount/note_value, note_count);

        amount -= notes_can_use*note_value;

        if(nextBundle->withdraw(amount, notes)){
            notes[mp[note_value]] = notes_can_use;
            note_count -= notes_can_use;

            return true;
        }

        return false;
    }

    unordered_map<int, int> mp;
};

class NullBundle : public Bundle{
public:
    NullBundle() = default;

    bool withdraw(int amount, vector<int> &notes){
        if(amount == 0){
            return true;
        }

        notes = {-1};

        return false;
    }

    void deposit(const vector<int> &banknotesCount){}

};

class TwentyBundel : public Bundle{
public:

    TwentyBundel(int notes, Bundle *bundle){
        note_count = notes;
        nextBundle = bundle;
    }

    bool withdraw(int amount, vector<int> &notes){
        return withdraw_helper(amount, note_value, note_count, nextBundle, notes);
    }

    void deposit(const vector<int> &banknotesCount){
        note_count += banknotesCount[mp[note_value]];
        nextBundle->deposit(banknotesCount);
    }

private:
    int note_count;
    const int note_value = 20;
    Bundle *nextBundle;

};

class FiftyBundel : public Bundle{
public:
    FiftyBundel(int notes, Bundle *bundle){
        note_count = notes;
        nextBundle = bundle;
    }

    bool withdraw(int amount, vector<int> &notes){
        return withdraw_helper(amount, note_value, note_count, nextBundle, notes);
    }

    void deposit(const vector<int> &banknotesCount){
        note_count += banknotesCount[mp[note_value]];
        nextBundle->deposit(banknotesCount);
    }

private:
    int note_count;
    const int note_value = 50;
    Bundle *nextBundle;

};

class HundredBundel : public Bundle{
public:
    HundredBundel(int notes, Bundle *bundle){
        note_count = notes;
        nextBundle = bundle;
    }

    bool withdraw(int amount, vector<int> &notes){
        return withdraw_helper(amount, note_value, note_count, nextBundle, notes);
    }

    void deposit(const vector<int> &banknotesCount){
        note_count += banknotesCount[mp[note_value]];
        nextBundle->deposit(banknotesCount);
    }

private:
    int note_count;
    const int note_value = 100;
    Bundle *nextBundle;

};

class TwoHundredBundel : public Bundle{
public:
    TwoHundredBundel(int notes, Bundle *bundle){
        note_count = notes;
        nextBundle = bundle;
    }

    bool withdraw(int amount, vector<int> &notes){
        return withdraw_helper(amount, note_value, note_count, nextBundle, notes);
    }

    void deposit(const vector<int> &banknotesCount){
        note_count += banknotesCount[mp[note_value]];
        nextBundle->deposit(banknotesCount);
    }

private:
    int note_count;
    const int note_value = 200;
    Bundle *nextBundle;

};

class FiveHundredBundel : public Bundle{
public:
    FiveHundredBundel(int notes, Bundle *bundle){
        note_count = notes;
        nextBundle = bundle;
    }

    bool withdraw(int amount, vector<int> &notes){
        return withdraw_helper(amount, note_value, note_count, nextBundle, notes);
    }

    void deposit(const vector<int> &banknotesCount){
        note_count += banknotesCount[mp[note_value]];
        nextBundle->deposit(banknotesCount);
    }

private:
    int note_count;
    const int note_value = 500;
    Bundle *nextBundle;

};

class ATM {
public:
    ATM() {
        bundle = new FiveHundredBundel(0, new TwoHundredBundel(0, 
        new HundredBundel(0, new FiftyBundel(0, new TwentyBundel(0, new NullBundle())))));
    }
    
    void deposit(vector<int> banknotesCount) {
        bundle->deposit(banknotesCount);
    }
    
    vector<int> withdraw(int amount) {
        vector<int> notes(5, 0);
        bundle->withdraw(amount, notes);
        return notes;
    }

private:
    Bundle *bundle;

};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
