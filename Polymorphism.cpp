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
    int ContentQuality;
    
public:

    YoutubeChannel (string name, string ownerName){
        Name= name;
        OwnerName= ownerName;
        SubscribersCount= 0;
        ContentQuality=0;
        }
        

    void GetInfo(){
         cout<<"Name: "<<Name<<endl;
        cout<<"OwnerName: "<<OwnerName<<endl;
        cout<<"SubscriberCount: "<<SubscribersCount<<endl;
        cout<<"Videos: "<<endl;
        for (string videoTitle: PublishedVideoTitles){
            cout<<videoTitle<<endl;}
    }
    

    void Subscribe(){
        SubscribersCount++;
    }
    
    
    void Unsubscribe(){
        if (SubscribersCount>0) SubscribersCount--;
    }
    
    void PublishVideo(string title){
        PublishedVideoTitles.push_back(title);
    }
    
    void CheckAnalytics(){
        if (ContentQuality<5)
            cout<< Name<<" has bad quality content"<<endl;
        else
        cout<<Name<<" has great content"<<endl;
    }
};


class CookingYoutubeChannel: public YoutubeChannel{
public:
    CookingYoutubeChannel(string name, string OwnerName): YoutubeChannel(name,OwnerName){}
    void Practice(){
        cout<< OwnerName<<"  practicing cooking,learning new recipes, experimenting with spices"<<endl;
        ContentQuality++;
    }
};

class SingersYoutubeChannel : public YoutubeChannel{
public: 
    SingersYoutubeChannel(string name, string OwnerName): YoutubeChannel(name,OwnerName){}
        void Practice(){
            cout<< OwnerName << " is taking singing classes, learning new songs, learning how to dance..."<<endl;
            ContentQuality++;
        }
};
        
int main(){
    CookingYoutubeChannel ytchannel("Amy's Kitchen","Amy");ytchannel.Practice();
    CookingYoutubeChannel ytchannel3("John's Kitchen","John");ytchannel3.Practice();
    SingersYoutubeChannel ytchannel4("Rik Sings","Rik");ytchannel4.Practice();
    
    ytchannel.Practice();
    ytchannel4.Practice();
    ytchannel4.Practice();
    ytchannel4.Practice();
    ytchannel4.Practice();
    
    //base class *pointer = address_of_derived_class
    //used polymorphism here
    //practice method is different for CookingYoutubeChannel
    //and SingersYoutubeChannel
    YoutubeChannel *yt1= &ytchannel;
    YoutubeChannel *yt2 = &ytchannel4;
    
    yt1->CheckAnalytics();
    yt2->CheckAnalytics();
    
}
    

