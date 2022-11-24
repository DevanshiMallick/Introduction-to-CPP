#include <iostream>
#include <list>
using namespace std;

class YoutubeChannel{
private:
//shoudnt be accessible by others, so make it private
    string Name;
    int SubscribersCount;
    list <string> PublishedVideoTitles;

protected:
//we want the ownerName property to be accessible by the derived class
    string OwnerName;
    
public:
    //constructors
    YoutubeChannel (string name, string ownerName){
        Name= name;
        OwnerName= ownerName;
        SubscribersCount= 0;
        }
        
    //class methos- we write info of class
    void GetInfo(){
         cout<<"Name: "<<Name<<endl;
        cout<<"OwnerName: "<<OwnerName<<endl;
        cout<<"SubscriberCount: "<<SubscribersCount<<endl;
        cout<<"Videos: "<<endl;
        for (string videoTitle: PublishedVideoTitles){
            cout<<videoTitle<<endl;}
    }
    
    // what if the user wants to subscrobe or Unsubscribe
    //we make class methods for that
    void Subscribe(){
        SubscribersCount++;
    }
    
    
    //has a bug---subscriber count cannot be in negative--so we introduce a if and else
    void Unsubscribe(){
        if (SubscribersCount>0) SubscribersCount--;
    }
    
    //what if we want to add a video title to the channel
    void PublishVideo(string title){
        PublishedVideoTitles.push_back(title);
    }
    
    //since Name and Owner Name are private members of the class - we can make a getter and setter methods
};

//cookingYoutubeChannel(derived class) inherits everything YoutubeChannel class(base class)
class CookingYoutubeChannel: public YoutubeChannel{
public:
    //constructor receives two properties
    //we are not initialise them in the constructorbecause one class already knows hown to initialse
    CookingYoutubeChannel(string name, string ownerName): YoutubeChannel(name,ownerName){}
    
    //only available for the objecys belonging to the class CookingYoutubeChannel
    //the base class will not have this function
    void Practice(){
        cout<<OwnerName<<"  practicing cooking,learning new recipes, experimenting with spices"<<endl;
    }
};
        
int main(){
    CookingYoutubeChannel ytchannel("Amy's Kitchen","Amy");
    //ytchannel.GetInfo();
    //ytchannel.PublishVideo("Apple Pie");
    //ytchannel.PublishVideo("Chocolate Cake");
    //ytchannel.Subscribe();
    //ytchannel.Subscribe();
    ytchannel.Practice();
    
    //checking if the base class can access the derived class's practice class methods
    //YoutubeChannel ytchannel2("ABC","DEF");
    //ytchannel2.GetInfo();
    
    //another CookingYoutubeChannel object
    // to access the ownerNamein the GetInfo part we have declared it in the protected part 
    //of the base class
    CookingYoutubeChannel ytchannel3("John's Kitchen","John");
    ytchannel3.Practice();
}
    
