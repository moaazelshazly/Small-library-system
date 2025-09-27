#include<iostream> 
#include<string> 
#include<vector>
#include<queue>
#include<stack>
using namespace std; 

void Listallbooks(string writer, string titel,int year); //to show all book
void addbooks(); 
bool searchbook(string book); 
void deletbook(); 
void countBooksByAuthor(); 
void borrow_book();
void Numbers_of_Books_Borrowed();
void return_book();
void theborrowers();
bool is_found(string book);

int const max_books=100; 
int years[max_books];//to save  the year when the book published 
int count=0,i;// count to know how match book in array and i where  to save book name in array 
string author_name[max_books], bookname[max_books];//to save authors name and books name 
string booktitle; 
int userchoice;// userchoice used to know what user want from program; 
vector<string>borrower; //to save the borrower name
vector<string>borrowed_book; // to know the borrowed book

int main(){ 
do{ 
cout <<"\n1- Add new book"<<endl; 
cout <<"2- List all books "<<endl; 
cout <<"3-Search for a book by title\n"; 
cout <<"4-Delete a book by title"<<endl; 
cout <<"5- Count books by author "<<endl; 
cout<<"6- Borrow a Book"<<endl;
cout<<"7- Number of borrowed books"<<endl;
cout<<"8- return a borrowed book"<<endl;
cout<<"9- know the borrowers name "<<endl;
cout <<"0-Exit "<<endl; 
cout<<"=========================="<<endl;
cout<<"Enter your choice :"; 

cin >>userchoice;

switch (userchoice) {
    case 1 :  if(count<100) 
addbooks(); 
            else 
            cout<<"bookshelf is full\n"; 
break; 
        case 2 : 
            for(i=0;i<count;i++){ 
                cout<<i+1<<" - ";
            Listallbooks(author_name[i], bookname[i],years[i]); 
                                } 
cout<<"=========================="<<endl;

break; 
        case 3 : cout<<"Name the book? "; cin>>booktitle;
        if(searchbook(booktitle))
            cout<<"found"<<endl;
        else cout<<"not found"<<endl;
cout<<"=========================="<<endl;


break; 
        case 4 : 
        deletbook(); 
        cout<<"=========================="<<endl;
break; 
        case 5: countBooksByAuthor(); 
        cout<<"=========================="<<endl;
break; 
        case 6:borrow_book();
        cout<<"=========================="<<endl;
break;
        case 7: Numbers_of_Books_Borrowed();
        cout<<"=========================="<<endl;
break;
        case 8: if(!borrower.empty())return_book();
        else cout<<"No book borrowed ! "<<endl;
        cout<<"=========================="<<endl;
break;
        case 9: theborrowers();
        cout<<"=========================="<<endl;
break;

}}while(userchoice!=0); 
} 
void Listallbooks(string writer, string titel,int year){ 
cout<<titel<<" by "<<writer<<" in "<<year<<endl;} 

void addbooks(){ 
cout << "Enter book title: "; 
cin>> bookname[count]; 
cout << "Enter author: "; 
cin>> author_name[count]; 
cout << "Enter publication year: "; 
cin >> years[count]; 
cout << "Book added successfully!\n"; 
cout<<"======================================"<<endl; 
count++; 
} 
// for find the book 

bool searchbook(string book){ 
for(i=0;i<count;i++) { 
if(book==bookname[i]) {    
return true;
} } 
return false;
}
//this function to delete the book
void deletbook(){ 
cout<<"enter the book title you want to delete: ";
cin>>booktitle;
int pos=0;
if(is_found(booktitle)&&searchbook(booktitle)){
for(i=0;i<count;i++){ 
if (booktitle==bookname[i]) 
{ 
    pos= i; 
break; 
}} 
for(i=pos;i<count;i++){ 
bookname[i]=bookname[i+1];; 
author_name[i]=author_name[i+1]; 
years[i]=years[i+1]; 
} 
count--; 
cout<<"Book deleted successfully!"<<endl; 
}else cout<<"you can't delete "<<booktitle <<" is not available "<<endl; 
}


//find how many book by the same author
void countBooksByAuthor(){ 
cout<<"enter author name: "; 
string b_author; 
cin>>b_author; 
int same_author=0; 
for(i=0;i<count;i++){ 
if (b_author==author_name[i]) 
same_author++; 
} 
cout<<"number of books by "<<b_author<<" : "<<same_author<<endl;
} 

void borrow_book(){
string the_borrower_name="";
cout<<"to borrow the book please enter book name ";
cin>>booktitle;

if(is_found(booktitle)&&searchbook(booktitle)){
    cout<<"and your name: ";
cin>>the_borrower_name; 

cout<<"Borrowed successfully !"<<endl;

borrowed_book.push_back(booktitle);
borrower.push_back(the_borrower_name);
}else  cout<<"This book is not available"<<endl;
}

void Numbers_of_Books_Borrowed(){
    cout<<"Number of Borrowed Book/s = "<<borrower.size()<<endl;
    char ans;
    if(borrowed_book.size())
    do
    {
cout<<"If you want to know the book titles press (y / n ) : ";
cin>>ans;
if(ans=='y'){
for(i=0;i<borrowed_book.size();i++){
    cout<< i+1<<" - "<< borrowed_book[i]<<endl;
    }    
}else if(ans=='n') return ;
else cout<<"invalid option"<<endl;
} while (!(ans=='y'||ans=='n'));
}


bool is_found(string book){
if(borrowed_book.empty()) return true;
int size=borrowed_book.size();
for(i=0;i<size;i++)
    if(borrowed_book[i]==book) return false;
return true;
}

void return_book(){
string name;
cout<<"Your name ? ";
cin>>name;
bool found=false;
    
for(int i=0;i<borrower.size();i++){
    if(borrower[i]==name){
    found = true;
    borrower.erase(borrower.begin()+i);
    borrowed_book.erase(borrowed_book.begin()+i);
    cout << "Book returned successfully ! "<<endl;
    cout<<"   Hope you enjoyed reading the book ! "<<endl;
    return; 
    }
}
if(!found)
    cout<<name<<" didn't borrow any book !"<<endl;
}

void theborrowers(){
    if(borrower.size()==0){
        cout<<"No borrower !"<<endl;
return;
    }else for(i=0;i<borrower.size();i++)
    cout<<i+1<<" - "<<borrower[i]<<endl;

}
