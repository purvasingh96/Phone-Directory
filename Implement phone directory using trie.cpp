#include<iostream>
#include<map>
using namespace std;

struct trie{
	map<char, struct trie*>child;
	int isleaf;
	trie(){
		char i;
		for(i='a';i<='z';i++){
			child[i]=NULL;
		}
		isleaf=0;
	}
};

struct trie *root= NULL;

void insert(string s){
	int len = s.length();
	struct trie *itr=root;
	int i;
	for(i=0;i<len;i++){
		struct trie *nextnode = itr->child[s[i]];
		if(nextnode==NULL){
			nextnode= new trie();
			itr->child[s[i]]=nextnode;
		}
		itr=nextnode;
		if(i==len-1){
			itr->isleaf=1;
		}
	}
}
void displayContactsUtil(struct trie *curNode, string prefix)
{
    if (curNode->isleaf)
        cout << prefix << endl;
 
    
    for (char i = 'a'; i <= 'z'; i++)
    {
        struct trie *nextNode = curNode->child[i];
        if (nextNode != NULL)
            displayContactsUtil(nextNode, prefix + (char)i);
    }
}
void displaycontacts(string str){
	struct trie *prevnode = root;
	string prefix="";
	int len = str.length();
	int i;
	for(i=0;i<len;i++){
		prefix+=(char)str[i];
		char lastchar = prefix[i];
		struct trie *currnode = prevnode->child[lastchar];
		if(currnode==NULL){
			cout<<"no results found for "<<prefix<<"\n";
			i++;
			break;
		}
		cout<<"suggestions based on "<<prefix<<"\n";
		displayContactsUtil(currnode, prefix);
		prevnode=currnode;
	}
}


void insertIntoTrie(string contacts[],int n)
{
    // Initialize root Node
    root = new trie();
 
    // Insert each contact into the trie
    for (int i = 0; i < n; i++)
        insert(contacts[i]);
}
 
int main()
{
    // Contact list of the User
    string contacts[] = {"purvasingh" , "purvakumar", "purvatribbiani"};
 
    // Size of the Contact List
    int n = sizeof(contacts)/sizeof(string);
 
    // Insert all the Contacts into Trie
    insertIntoTrie(contacts, n);
 
    string query = "purvabaker";
 
    displaycontacts(query);
 
    return 0;
}















