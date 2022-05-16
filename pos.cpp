#include <iostream>
#include <fstream>

using namespace std;

class shopping{
    private:
        int pcode;
        float price;
        float disc;
        string pname;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();

};

void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t..............................\n";
    cout<<"\t\t\t                              \n";
    cout<<"\t\t\t          Supermarket         \n";
    cout<<"\t\t\t                              \n";
    cout<<"\t\t\t..............................\n";
    cout<<"\t\t\t                              \n";
    cout<<"\t\t\t | 1) Administrator  |\n";
    cout<<"\t\t\t |                   |\n";
    cout<<"\t\t\t | 2) Buyer          |\n";
    cout<<"\t\t\t |                   |\n";
    cout<<"\t\t\t | 3) Exit           |\n";
    cout<<"\n\t\t\t | Please Select!  |\n";
    cin>>choice;

    switch(choice){
        case 1:
        cout<<"\t\t\t | Please Login      |\n";
        cout<<"\t\t\t | Enter Email       |\n";
        cin>>email;
        cout<<"\t\t\t | Enter Password     |\n";
        cin>>password;

        if(email == "sam@gmail.com" && password == "sam@123"){
            administrator();
        }else{
            cout<<"\t\t\t | Invalid email or password     |\n";
        }
        break;
        
        case 2:
        {
            buyer();
        }
        
        case 3:
        {
            exit(0);
        }
        
        default:
        {
            cout<<"\t\t\t | Invalid Option |\n"; 
        }
        
        
    }
    goto m;
}

void shopping :: administrator(){
    m:
    int choice;
     cout<<"\n\n\t\t | Administrator Menu         |\n";
     cout<<"\n\t\t\t |.1) Add a product           |\n";
     cout<<"\n\t\t\t |                            |\n";
     cout<<"\n\t\t\t | 2) Modify a Product        |\n";
     cout<<"\n\t\t\t |                            |\n";
     cout<<"\n\t\t\t | 3) Delete a Product        |\n";
     cout<<"\n\t\t\t |                            |\n";
     cout<<"\n\t\t\t | 4) Back to main menu       |\n";
     cout<<"\n\t\t\t |                            |\n";
     cout<<"\n\t\t\t | Enter your choice here      |\n";
     cin>>choice;

     switch(choice){
         case 1:
         add();
         break;

         case 2:
         edit();
         break;

         case 3:
         rem();
         break;

         case 4:
         menu();
         break;

         default:
         cout<<"Invalid";
     }
     goto m;
}

void shopping :: buyer(){
    m:
    int choice;
    cout<<"\n\t\t\t  Buyer                 |\n";
    cout<<"\n\t\t\t |                      |\n";
    cout<<"\n\t\t\t | 1) Buy Product       |\n";
    cout<<"\n\t\t\t |                      |\n";
    cout<<"\n\t\t\t | 1) Go Back           |\n";
    cout<<"\n\t\t\t |                      |\n";
    cout<<"\n\t\t\t  Enter your choice     |\n";
    cin>>choice;

    switch(choice){
        case 1:
        receipt();
        break;

        case 2:
        menu();
        break;

        default:
        cout<<"\n\t\t\t   Invalid choice    \n";
    }
    goto m;
    
}

void shopping :: add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Add new product      |\n";
    cout<<"\n\t\t\t  Product code of the product     \n";
    cin>>pcode;
    cout<<"\n\t\t Name of the product    \n";
    cin>>pname;     
    cout<<"\n\t\t Product Price       \n";
    cin>>price;                 
    cout<<"\n\t\t Product Discount       \n";
    cin>>disc;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
        data.close();
    }else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c == pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }

    if(token == 1){
        goto m;
    }else{
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
        data.close();
    }
    cout<<"\n\t Record inserted !";
}

void shopping :: edit(){
    fstream data, data1;
    int pkey;
    int token= 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify product \t";
    cout<<"\n\t\t\t Product code \t";
    cin>>pkey;

    data.open("database.txt",ios::in);

    if(!data){
        cout<<"\n\t\t\t File does not exist! \t";
    }else{

        data1.open("database.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>disc;
        while(!data.eof()){
            if(pkey == pcode){
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product    \n";
                cin>>n;     
                cout<<"\n\t\t Product Price       \n";
                cin>>p;                 
                cout<<"\n\t\t Product Discount       \n";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t Record edited     \n";
                token++;
            }else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
            }
            data>>pcode>>pname>>price>>disc;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");
    
        if(token == 0){
            cout<<"\n\n Record could not be found! ";
        }
    }
}

void shopping::rem(){
    fstream data,data1;
    int pkey;
    int token = 0;
    cout<<"\n\n\t Delete a product";
    cout<<"\n\n\t ENTER PRODUCT CODE";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data){
        cout<<"File doesn't exist";
    }
    else{
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>disc;

        while(!data.eof()){
            if(pcode == pkey){
              cout<<"Product deleted successfully";  
              token++;
            }else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
            }
            data>>pcode>>pname>>price>>disc;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token == 0){
            cout<<"\n\n Record could not be found! ";
        }
    }
}

void shopping::list(){
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n|..............................\t\t";
    cout<<"ProdNo\t\tName\t\tPrice\n";
    cout<<"\n\n|..............................\t\t";
    data>>pcode>>pname>>price>>disc;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>disc;
    }
    data.close();
}

void shopping :: receipt(){
    fstream data;

    int arrc[100];
    int arrq[100];
    string choice;
    int c = 0;
    int q = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout<<"\n\n|RECEIPT \t\t";
    data.open("database.txt", ios::in);

    if(!data){
        cout<<"\n\n Empty Database \t\t";
    }
    else{
        data.close();

        list();
        cout<<"\t\t\t..............................\n";
        cout<<"\t\t\t                              \n";
        cout<<"\t\t\t          Place Order         \n";
        cout<<"\t\t\t                              \n";
        cout<<"\t\t\t..............................\n";
        cout<<"\t\t\t                              \n";

        do{
            m:
           cout<<"\n\n Enter Product Code \t\t"; 
           cin>>arrc[c];
           cout<<"\n\n Enter Quantity \t\t";
           cin>>arrq[q];

           for(int i = 0; i<c; i++){
               if(arrc[c] == arrc[i]){
                   cout<<"\n\t\t Duplicate Product code. TRY AGAIN!";
                   goto m;
               }
           }
           c++;
          cout<<"\n\t\t Do you want to buy another product?Press y for yes or n for no!"; 
          cin>>choice;
        }

        while(choice == "y");

        cout<<"\n\t\t ..............RECEIPT..........!\n\t";
        cout<<"\n\t\t Product name\t Product quantity\tPrice\tAmount!";

        for(int i = 0; i<c; i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;

            while(!data.eof()){
                if(pcode == arrc[i]){
                    amount = price*arrq[i];
                    dis=amount-(amount*dis/100);
                    cout<<"\n\t\t" <<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t"<<amount<<"\t\t"<<dis<<"\t";
                
                }
                data>>pcode>>pname>>price>>dis;
            }
            
        }
        data.close();
    }

     cout<<"\n\t\t ........................!\n\t";
     cout<<"\n\t\t Total Amount : "<<total;
}

int main(){
    shopping s;
    s.menu();
}