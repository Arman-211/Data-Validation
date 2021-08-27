#include <iostream>
#include <regex>
#include <climits>
#include <string>

bool dataCheck(std::string data){
    const std::regex pattern("^(1[0-2]|0?[1-9])/(3[01]|[12][0-9]|0?[1-9])/(?:[0-9]{2})?[0-9]{2}$");
    return std::regex_match(data,pattern);
}
void dataValidation(std::string data)
{
    if (dataCheck(data)){
        std::cout<<std::endl;
        std::cout<<"Your Data is valid"<<std::endl;
    }
    else
    {
        std::cout<<std::endl;
        std::cout<<"ERROR..........."<<std::endl;
        std::cout<<"Your Data is invalid"<<std::endl;
    }
}
bool urlCheck(std::string url){
    const std::regex pattern("^(http:\\/\\/www\\.|https:\\/\\/www\\.|http:\\/\\/|https:\\/\\/|www\\.)[a-z0-9]+([\\-\\.]{1}[a-z0-9]+)*\\.[a-z]{2,5}(:[0-9]{1,5})?(\\/.*)?$");
    return std::regex_match(url,pattern);
}
void urlValidation(std::string url)
{
    if (urlCheck(url)){
        std::cout<<std::endl;
        std::cout<<"Your URL is valid"<<std::endl;
    }
    else
    {
        std::cout<<std::endl;
        std::cout<<"ERROR..........."<<std::endl;
        std::cout<<"Your URL is invalid"<<std::endl;
    }
}

bool emilCheck(std::string address){
    const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(address,pattern);
}
void emilValidation(std::string address)
{
    if (emilCheck(address)){
            std::cout<<std::endl;
            std::cout<<"Your Emil is valid"<<std::endl;
        }
    else
        {
            std::cout<<std::endl;
            std::cout<<"ERROR..........."<<std::endl;
            std::cout<<"Your Emil is invalid"<<std::endl;
        }
}
bool isInteger(std::string number){
    for (int i = 0; i < number.size(); ++i) {
        if (number[i]<'0' || number[i]>'9'){
            return false;
        }
    }
    return true;
}
void numberValidation(std::string number){
    if (!isInteger(number)){
        std::cout<<std::endl;
        std::cout<<"ERROR..........."<<std::endl;
        std::cout<<"Your Number is invalid"<<std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "Your Number is valid" << std::endl;
    }
}
bool cartVal(std::string cart){
    int size = cart.size();
    int sum = 0;
    bool flag = false;
    for (int i = size - 1; i >= 0 ; i--) {
        int d = cart[i] - '0';
        if (flag){
            d = d * 2;
        }
        sum += d / 10;
        sum += d % 10;
        flag = !flag;
    }
    return (sum % 10 == 0);
}
void cartValidation(std::string cart){

    if (!cartVal(cart)){
        std::cout<<std::endl;
        std::cout<<"ERROR..........."<<std::endl;
        std::cout<<"Your Credit Card Number is invalid"<<std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "Your Credit Card Number is valid" << std::endl;
    }

}
bool phoneVal(char* phone){
    int  a = phone[0];
    int size = strlen(phone);
    if(size == 9){
        for (int i = 0; i < size; ++i) {
            if (a == '0'){
                return true;
            }
        }
    }

    return false;

}

void phoneValidation(char* phone){
    if (!phoneVal(phone)){
        std::cout<<std::endl;
        std::cout<<"ERROR..........."<<std::endl;
        std::cout<<"Your Phone Number is invalid"<<std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "Your Phone Number is valid" << std::endl;
    }
}
int main(){
    int yesORno;


    std::cout<<"What do you want to enter and check?"<<std::endl;

    std::cout<<"Emil Address(entre/1)";
    std::cout<<std::endl;
    std::cout<<"Website URL(entre/2)";
    std::cout<<std::endl;
    std::cout<<"Data M/D/Y(entre/3)";
    std::cout<<std::endl;
    std::cout<<"Integer Number(entre/4)";
    std::cout<<std::endl;
    std::cout<<"Credit Card Number(entre/5)";
    std::cout<<std::endl;
    std::cout<<"Mobil Phone Number(entre/6)";
    std::cout<<std::endl;

    std::cin>>yesORno;

    if (yesORno == 1)
    {
        std::string address;
        std::cout <<"Enter emil Address:";
        std::cin>>address;

        emilValidation(address);

    }else if (yesORno == 2)
    {
        std::string url;
        std::cout <<"Enter Website URL :";
        std::cin>>url;
        urlValidation(url);
    }else if (yesORno == 3)
    {
        std::string data;
        std::cout <<"Enter Data (mm/dd/yyyy):";
        std::cin>>data;
        dataValidation(data);
    }else if (yesORno == 4)
    {
        std::string number;
        std::cout <<"Enter Integer Number :";
        std::cin>>number;
        numberValidation(number);
    }else if (yesORno == 5)
    {
        std::string cart;
        std::cout <<"Enter Credit Card Number :";
        std::cin>>cart;
        cartValidation(cart);
    }else  if (yesORno == 6)
    {
        char phone[9];
        std::cout <<"Enter Phone Number (0**-***-***) :";
        std::cin>>phone;
        phoneValidation(phone);

    } else
    {
     std::cout<<"\t\t..........^^^PLEASE TRY AGAIN^^^ .........."<<std::endl;
    }

    return 0;
}

