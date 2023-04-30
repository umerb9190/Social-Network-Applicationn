
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class LikedBy;
class User;
class Facebook;
class Comment;




//1 - Set Current User
//a.Ask user about his ID and set him as current user of application.Now everything that we
//see in the system will be view of this user.
//
//2 - View Home of Current User
//a.Display posts of all friends shared in last 24 hours.
//b.Display posts of all his liked pages shared in last 24 hours.
//3 - Like a post
//a.Ask user about ID of post and like it.A post can be liked by 10 users at max.
//4 - View the list of People who liked a post
//a.Take Post ID from user and display list of people who have liked it
//5 - Comment on a Post
//a.Take post ID and comment from the user and add this comment in the post
//6 - View a Post
//a.Take post ID and Display the post with its Comments
//7 - Share a Memory
//a.Take post ID, text from userand share it
//8 - View User’s Timeline
//a.Display User Name
//b.Display user’s posts in his timeline
//9 - View Friend List
//a.Take ID of a user and display his friends list
//10 - View Page
//a.Take Page ID and display all its posts







class LikedBy
{
protected:
	char* id;
	char* name;
public:
	LikedBy()
	{
		id = nullptr;
		name = nullptr;
	}
	LikedBy(const LikedBy& obj)
	{
		deepcopy(id, obj.id);
		deepcopy(name, obj.name);
	}
	void setid(char* _id)
	{
		deepcopy(id, _id);
	}
	void setname(char* _name)
	{
		deepcopy(name, _name);
	}
	char* getid()
	{
		if (id != nullptr)
		{
			char* ptr;
			deepcopy(ptr, id);
			return ptr;
		}
		return nullptr;
	}
	char* getname()
	{
		if (name != nullptr)
		{
			char* ptr;
			deepcopy(ptr, name);
			return ptr;
		}
		return nullptr;
	}
	void deepcopy(char*& ptr, char* qtr)
	{
		int size = 0;
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			size++;
		}
		ptr = new char[size + 1];
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			ptr[i] = qtr[i];
		}
		ptr[size] = '\0';
	}
	~LikedBy()
	{
		delete id;
		delete name;
	}
};

class SharedBY
{
protected:
	char* id;
	char* name;
public:
	SharedBY()
	{
		id = nullptr;
		name = nullptr;
	}
	SharedBY(const SharedBY& obj)
	{
		copy(id, obj.id);
		copy(name, obj.name);
	}
	void setid(char* _id)
	{
		copy(id, _id);
	}
	char* getid()
	{
		char* ptr = nullptr;
		copy(ptr, id);
		return ptr;
	}
	void setname(char* _name)
	{
		copy(name, _name);
	}
	void copy(char*& ptr, char* qtr)
	{
		int size = 0;
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			size++;
		}
		ptr = new char[size + 1];
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			ptr[i] = qtr[i];
		}
		ptr[size] = '\0';
	}
	~SharedBY()
	{
		delete id;
		delete name;
	}
};

class Comment
{
private:
	char* postid; //which post
	char* commentid; //c1,c2,..
	char* userid;//comment by
	char* commenttext;//comment
public:
	Comment()
	{
		postid = nullptr;
		commentid = nullptr;
		userid = nullptr;
		commenttext = nullptr;
	}
	Comment(const Comment& obj)
	{
		deepcopy(postid, obj.postid);
		deepcopy(commentid, obj.commentid);
		deepcopy(userid, obj.userid);
		deepcopy(commenttext, obj.commenttext);
	}
	void setcommenttext(char* _commenttext)
	{
		deepcopy(commenttext, _commenttext);
	}
	void setpostid(char* _postid)
	{
		deepcopy(postid, _postid);
	}
	char* getuserid()
	{
		if (userid != nullptr)
		{
			char* ptr = nullptr;
			deepcopy(ptr, userid);
			return ptr;
		}
		return nullptr;
	}
	char* getpostid()
	{
		if (postid != nullptr)
		{
			char* ptr = nullptr;
			deepcopy(ptr, postid);
			return ptr;
		}
		return nullptr;
	}
	char* getcommentid()
	{
		if (commentid != nullptr)
		{
			char* ptr = nullptr;
			deepcopy(ptr, commentid);
			return ptr;
		}
		return nullptr;
	}
	char* getcommenttext()
	{
		if (commenttext != nullptr)
		{
			char* ptr = nullptr;
			deepcopy(ptr, commenttext);
			return ptr;
		}
		return nullptr;
	}
	void setcommentid(char* _commentid)
	{
		deepcopy(commentid, _commentid);
	}
	void setuserid(char* _userid)
	{
		deepcopy(userid, _userid);
	}
	void deepcopy(char*& ptr, char* qtr)
	{
		int size = 0;
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			size++;
		}
		ptr = new char[size + 1];
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			ptr[i] = qtr[i];
		}
		ptr[size] = '\0';
	}
	~Comment()
	{
		delete postid;
		delete commentid;
		delete userid;
		delete commenttext;
	}
	void display()
	{
		cout << commentid << " " << postid << " " << userid << endl;
		cout << commenttext << endl;
	}
};

class Post
{
protected:
	char* postid;
	int date;
	int month;
	int year;
	char* postdesc;//post destination text
	SharedBY share;// composition
	LikedBy* like;//association..liked by
	int likesize;
	Comment* comment;
	int commentsize;
public:
	Post()
	{
		commentsize = 0;
		likesize = 0;
		postid = nullptr;
		postdesc = nullptr;
		like = new LikedBy[10];
		comment = new Comment[10];
	}
	Post(const Post& obj)
	{
		copy(postid, obj.postid);
		date = obj.date;
		month = obj.month;
		year = obj.year;
		copy(postdesc, obj.postdesc);
	}


	virtual void setpostid(char* id) = 0;
	virtual char* getpostid() = 0;
	virtual void display(char* name) = 0;
	virtual bool cmp(char* ptr, char* qtr) = 0;


	void setlikeby(char* id, char* name)
	{
		like[likesize].setid(id);
		like[likesize++].setname(name);
	}
	void displaylikeby()
	{
		for (int i = 0; i < likesize; i++)
		{
			if (like[i].getid() != nullptr && like[i].getname() != nullptr)
			{
				cout << like[i].getid() << " - " << like[i].getname() << endl;
			}
		}
	}
	void commentdisplay()
	{

		for (int i = 0; i < commentsize; i++)
		{
			if (comment[i].getcommenttext() == nullptr)
			{
				cout << "#" << i << endl;
			}
			if (comment[i].getcommenttext() != nullptr)
			{
				cout << "\t" << comment[i].getcommenttext() << endl;
			}
		}
	}
	void copy(char*& ptr, const char* qtr)
	{
		int size = 0;
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			size++;
		}
		ptr = new char[size + 1];

		for (int i = 0; qtr[i] != '\0'; i++)
		{
			ptr[i] = qtr[i];
		}
		ptr[size] = '\0';
	}

	char* getcommenttext(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, comment[temp].getcommenttext());
		return ptr;
	}

	int getpostdate()
	{
		return date;
	}
	int getpostmonth()
	{
		return month;
	}
	int getpostyear()
	{
		return year;
	}
	char* getpostdesc()
	{
		if (postdesc != nullptr)
		{
			char* ptr = nullptr;
			copy(ptr, postdesc);
			return ptr;
		}
		return nullptr;
	}
	void setshareid(char* _shareid)
	{
		share.setid(_shareid);
	}
	char* getshareid()
	{
		return share.getid();
	}
	void setsharename(char* _sharename)
	{
		share.setname(_sharename);
	}
	void setlikeid(char* _likeid)
	{
		if (likesize < 10)
			like[likesize].setid(_likeid);
	}
	void setlikename(char* _likename)
	{
		if (likesize < 10)
		{
			like[likesize++].setname(_likename);
		}
	}
	void setcomment(char* _commenttext)
	{
		if (commentsize < 10)
		{
			comment[commentsize++].setcommenttext(_commenttext);
		}
	}

	virtual~Post()
	{
		delete postid;
		delete postdesc;
	}
};

class Activity :public Post
{
private:
	int type;
	char* value;
public:
	Activity()
	{
		type = 0;
		value = nullptr;
	}
	Activity(const Activity& obj) :Post(obj)
	{
		type = obj.type;
		copy(value, obj.value);
	}
	void settype(int _type)
	{
		type = _type;
	}
	void setvalue(char* _value)
	{
		copy(value, _value);
	}
	void setpostid(char* id)
	{
		copy(postid, id);
	}
	const char* gettype()
	{
		if (type == 1)
		{
			return "feeling";
		}
		else if (type == 2)
		{
			return "thinking about";
		}
		else if (type == 3)
		{
			return "making";
		}
		else if (type == 4)
		{
			return "celebrating";
		}
		else
		{
			return nullptr;
		}
	}
	char* getvalue()
	{
		if (gettype() != nullptr)
		{
			char* ptr = nullptr;
			copy(ptr, value);
			return ptr;
		}
		return nullptr;
	}
	char* getpostid()
	{
		if (postid != nullptr)
		{
			char* ptr = nullptr;
			copy(ptr, postid);
			return ptr;
		}
		return nullptr;
	}
	void setfulldate(int dat, int mon, int yr)
	{
		date = dat;
		month = mon;
		year = yr;
	}
	void setdesc(char* _postdesc)
	{
		copy(postdesc, _postdesc);
	}
	~Activity()
	{
		delete value;
	}
	void display(char* name)
	{
		ifstream fin;
		if (postdesc != nullptr)
		{
			cout << name << " ";
			if (gettype() != nullptr)
			{
				cout << "is " << gettype() << " " << getvalue() << endl;
			}
			else
			{
				cout << "shared  ";
			}
			cout << "\"" << postdesc << "\"" << endl << endl;

			fin.open("FacebookComments.txt");
			int totalcomment = 0;
			char garb[200];
			char commentid[10];
			char _postid[10];
			char commenttext[60];
			char userid[10];

			fin >> totalcomment;
			fin.getline(garb, 200, '\n');

			for (int j = 0; j < totalcomment; j++)
			{
				fin >> commentid >> _postid >> userid;
				fin.ignore();
				fin.getline(commenttext, 60, '\n');
				if (cmp(_postid, postid) == 0)
				{
					cout << "\t\t" << userid;
					cout << " wrote: \"" << commenttext << "\"" << endl;
					break;
				}
			}
			fin.close();

		}
	}
	bool cmp(char* ptr, char* qtr)
	{
		int size1 = 0, size2 = 0;
		for (int i = 0; i < ptr[i] != '\0'; i++)
		{
			size1++;
		}
		for (int i = 0; i < qtr[i] != '\0'; i++)
		{
			size2++;
		}
		if (size1 == size2)
		{
			for (int i = 0; i < ptr[i] != '\0'; i++)
			{
				if (ptr[i] != qtr[i])
				{
					return 1;
				}
			}
			return 0;
		}
		return 1;
	}
};

class Page
{
private:
	char* pageid;
	char* pagetitle;
	Activity* post;// liked // for user its share 
	int postsize;
public:
	Page()
	{
		postsize = 0;
		pageid = nullptr;
		pagetitle = nullptr;
		post = new Activity[10];
	}
	Page(const Page& obj)
	{
		copy(pagetitle, obj.pagetitle);
	}
	int getpostsize()
	{
		return postsize;
	}
	void setpageid(char* _pageid)
	{
		copy(pageid, _pageid);
	}
	char* getpageid()
	{
		char* ptr = nullptr;
		copy(ptr, pageid);
		return ptr;
	}
	void setpagetitle(char* _pagetitle)
	{
		copy(pagetitle, _pagetitle);
	}
	char* getpagetitle()
	{
		char* ptr = nullptr;
		copy(ptr, pagetitle);
		return ptr;
	}
	void setpagepostid(char* _postid)
	{
		post[postsize++].setpostid(_postid);
	}
	char* getpagepostid(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, post[temp].getpostid());
		return ptr;
	}
	void setpagepostdate(int dat, int mon, int yr)
	{
		post[postsize - 1].setfulldate(dat, mon, yr);
	}
	int getpagepostdate(int temp)
	{
		return post[temp].getpostdate();
	}
	int getpagepostmonth(int temp)
	{
		return post[temp].getpostmonth();
	}
	int getpagepostyear(int temp)
	{
		return post[temp].getpostyear();
	}
	void setpagepostdesc(char* _postdesc)
	{
		post[postsize - 1].setdesc(_postdesc);
	}
	char* getpagepostdesc(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, post[temp].getpostdesc());
		return ptr;
	}
	void setpageposttypeandvalue(int _type, char* _value)
	{
		post[postsize - 1].settype(_type);
		post[postsize - 1].setvalue(_value);
	}
	int getpageposttype(int temp)
	{
		if (post[temp].gettype() != nullptr)
		{
			if (post[temp].gettype()[0] == 'f')// feeling
				return 1;
			else if (post[temp].gettype()[0] == 't') // thinking 
				return 2;
			else if (post[temp].gettype()[0] == 'm') // making 
				return 3;
			else if (post[temp].gettype()[0] == 'c') // celebrating
				return 4;
			else
				return 0;
		}
		return 0;
	}
	char* getposttypechar(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, post[temp].gettype());
		return ptr;
	}
	char* getpagepostvalue(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, post[temp].getvalue());
		return ptr;
	}
	void setpagepostshare(char* _postid)
	{
		post[postsize - 1].setshareid(_postid);
		post[postsize - 1].setsharename(pagetitle);
	}
	void setpostlikeid(char* _likeid)
	{
		post[postsize - 1].setlikeid(_likeid);
	}
	void setpostlikename(char* _likename)
	{
		post[postsize - 1].setlikename(_likename);
	}
	~Page()
	{
		delete pageid;
		delete pagetitle;
	}
	void display()
	{
		cout << pageid << " -- " << pagetitle << endl;
	}
	void pagedisplaypost()
	{
		ifstream fin;
		for (int i = 0; i < postsize; i++)
		{
			if (getpagepostdesc(i) != nullptr)
			{
				cout << pagetitle << " ";
				if (getpageposttype(i) > 0)
				{
					cout << "is " << post[i].gettype() << " " << getpagepostvalue(i) << endl;
				}
				else
				{
					cout << "shared  ";
				}
				cout << "\"" << getpagepostdesc(i) << "\"" << endl << endl;

				fin.open("FacebookComments.txt");
				int totalcomment = 0;
				char garb[200];
				char commentid[10];
				char postid[10];
				char commenttext[60];
				char userid[10];

				fin >> totalcomment;
				fin.getline(garb, 200, '\n');

				for (int j = 0; j < totalcomment; j++)
				{
					fin >> commentid >> postid >> userid;
					fin.ignore();
					fin.getline(commenttext, 60, '\n');
					for (int k = 0; k < postsize; k++)
					{
						if (cmp(postid, post[k].getpostid()) == 0)
						{
							cout << "\t\t" << userid;
							cout << " wrote: \"" << commenttext << "\"" << endl;
							break;
						}
					}
				}
				fin.close();

			}
		}
	}
	void copy(char*& ptr, const char* qtr)
	{
		int size = 0;
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			size++;
		}
		ptr = new char[size + 1];
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			ptr[i] = qtr[i];
		}
		ptr[size] = '\0';
	}
	bool cmp(char* ptr, char* qtr)
	{
		int size1 = 0, size2 = 0;
		for (int i = 0; i < ptr[i] != '\0'; i++)
		{
			size1++;
		}
		for (int i = 0; i < qtr[i] != '\0'; i++)
		{
			size2++;
		}
		if (size1 == size2)
		{
			for (int i = 0; i < ptr[i] != '\0'; i++)
			{
				if (ptr[i] != qtr[i])
				{
					return 1;
				}
			}
			return 0;
		}
		return 1;
	}
};

class Friend
{
private:
	char* frdid;
	char* frdname;
	Page* page;
	int pagesize;
	Activity* post;
	int postsize;
public:
	Friend()
	{
		frdid = nullptr;
		frdname = nullptr;
		pagesize = 0;
		postsize = 0;
		page = new Page[10];
		post = new Activity[10];
	}
	Friend(const Friend& obj)
	{
		deepcopy(frdid, obj.frdid);
		deepcopy(frdname, obj.frdname);
		pagesize = obj.pagesize;
		for (int i = 0; i < pagesize; i++)
		{
			page[i] = obj.page[i];
		}
		postsize = obj.postsize;
		for (int i = 0; i < postsize; i++)
		{
			post[i] = obj.post[i];
		}
	}
	Friend& operator=(const Friend& obj)
	{
		deepcopy(frdid, obj.frdid);
		deepcopy(frdname, obj.frdname);
		pagesize = obj.pagesize;
		for (int i = 0; i < pagesize; i++)
		{
			page[i] = obj.page[i];
		}
		postsize = obj.postsize;
		for (int i = 0; i < postsize; i++)
		{
			post[i] = obj.post[i];
		}
		return *this;
	}
	void setfrdpageid(char* _pageid)
	{
		page[pagesize].setpageid(_pageid);
	}
	char* getfrdpageid(int temp)
	{
		char* ptr = nullptr;
		deepcopy(ptr, page[temp].getpageid());
		return ptr;
	}
	void setfrdpagetitle(char* _pagetitle)
	{
		page[pagesize++].setpagetitle(_pagetitle);
	}
	char* getfrdpagetitle(int temp)
	{
		char* ptr = nullptr;
		deepcopy(ptr, page[temp].getpagetitle());
		return ptr;
	}
	void setfrdpostid(char* _postid)
	{
		post[postsize].setpostid(_postid);
	}
	char* getfrdpostid(int temp)
	{
		char* ptr = nullptr;
		deepcopy(ptr, post[temp].getpostid());
		return ptr;
	}
	void setfrdpostdate(int dt, int mon, int yr)
	{
		post[postsize++].setfulldate(dt, mon, yr);
	}
	void setfrdpostdesc(char* _postdesc)
	{
		post[postsize - 1].setdesc(_postdesc);
	}
	char* getfrdpostdesc(int temp)
	{
		char* ptr = nullptr;
		deepcopy(ptr, post[temp].getpostdesc());
		return ptr;
	}
	int getfrdpostdate(int temp)
	{
		return post[temp].getpostdate();
	}
	int getfrdpostmonth(int temp)
	{
		return post[temp].getpostmonth();
	}
	int getfrdpostyear(int temp)
	{
		return post[temp].getpostyear();
	}
	void setfrdposttype(int type)
	{
		post[postsize - 1].settype(type);
	}
	void setfrdpostvalue(char* value)
	{
		post[postsize - 1].setvalue(value);
	}
	char* gettype(int temp)
	{
		if (post[temp].gettype() != nullptr)
		{
			char* ptr = nullptr;
			deepcopy(ptr, post[temp].gettype());
			return ptr;
		}
		return nullptr;
	}
	char* getvalue(int temp)
	{
		if (gettype(temp) != nullptr)
		{
			char* ptr = nullptr;
			deepcopy(ptr, post[temp].getvalue());
			return ptr;
		}
		return nullptr;
	}
	int getfrdpagesize()
	{
		return pagesize;
	}
	int getfrdpostsize()
	{
		return postsize;
	}
	void setfrdid(char* _frdid)
	{
		deepcopy(frdid, _frdid);
	}
	char* getfrdid()
	{
		char* ptr = nullptr;
		deepcopy(ptr, frdid);
		return ptr;
	}
	void setfrdname(char* _frdname)
	{
		deepcopy(frdname, _frdname);
	}
	char* getfrdname()
	{
		char* ptr = nullptr;
		deepcopy(ptr, frdname);
		return ptr;
	}
	void deepcopy(char*& ptr, const char* qtr)
	{
		int size = 0;
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			size++;
		}
		ptr = new char[size + 1];
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			ptr[i] = qtr[i];
		}
		ptr[size] = '\0';
	}
	~Friend()
	{
		delete frdid;
		delete frdname;
	}
	void display()
	{
		cout << frdid << " -- " << frdname << endl;
	}
	void displaypost()
	{
		ifstream fin;
		for (int i = 0; i < postsize; i++)
		{
			if (getfrdpostdesc(i) != nullptr)
			{
				cout << frdname << " ";
				if (gettype(i) != nullptr)
				{
					cout << "is " << gettype(i) << " " << getvalue(i) << endl;
				}
				else
				{
					cout << "shared  ";
				}
				cout << "\"" << getfrdpostdesc(i) << "\"" << endl << endl;
				post[i].commentdisplay();



				fin.open("FacebookComments.txt");
				int totalcomment = 0;
				char garb[200];
				char commentid[10];
				char postid[10];
				char commenttext[60];
				char userid[10];

				fin >> totalcomment;
				fin.getline(garb, 200, '\n');

				for (int j = 0; j < totalcomment; j++)
				{
					fin >> commentid >> postid >> userid;
					fin.ignore();
					fin.getline(commenttext, 60, '\n');
					for (int k = 0; k < postsize; k++)
					{
						if (cmp(postid, post[k].getpostid()) == 0)
						{
							cout << "\t\t" << userid;
							cout << " wrote: \"" << commenttext << "\"" << endl;
							break;
						}
					}
				}
				fin.close();


			}

		}
	}
	bool cmp(char* ptr, char* qtr)
	{
		int size1 = 0, size2 = 0;
		for (int i = 0; i < ptr[i] != '\0'; i++)
		{
			size1++;
		}
		for (int i = 0; i < qtr[i] != '\0'; i++)
		{
			size2++;
		}
		if (size1 == size2)
		{
			for (int i = 0; i < ptr[i] != '\0'; i++)
			{
				if (ptr[i] != qtr[i])
				{
					return 1;
				}
			}
			return 0;
		}
		return 1;
	}
};

//User::User(ifstream& obj1)
//{
//	char ch;
//	int count = 0;
//	char* temp;
//	int count1 = 0;
//	temp = new char[50];
//	int i;
//	int count2 = 0;
//	if (obj1)
//	{
//		while (!obj1.eof())
//		{
//			obj1 >> ch;
//			if (ch == '-')
//			{
//				break;
//			}
//			else
//			{
//				temp[count1] = ch;
//				count1++;
//			}
//
//		}
//		id = new char[count1 + 1];
//		for (i = 0; i < count1; i++)
//		{
//			id[i] = temp[i];
//		}
//		id[i] = '\0';
//		count1 = 0;
//		while (!obj1.eof())
//		{
//			obj1 >> ch;
//			if (ch == '-')
//			{
//				break;
//			}
//			else
//			{
//				temp[count1] = ch;
//				count1++;
//			}
//
//		}
//		FName = new char[count1 + 1];
//		for (i = 0; i < count1; i++)
//		{
//			FName[i] = temp[i];
//		}
//		FName[i] = '\0';
//		count1 = 0;
//		while (!obj1.eof())
//		{
//			obj1 >> ch;
//			if (ch == '-')
//			{
//				break;
//			}
//			else
//			{
//				temp[count1] = ch;
//				count1++;
//			}
//
//		}
//		LName = new char[count1 + 1];
//		for (i = 0; i < count1; i++)
//		{
//			LName[i] = temp[i];
//		}
//		LName[i] = '\0';
//
//
//		count1 = 0;
//
//		while (!obj1.eof())
//		{
//			obj1 >> ch;
//			//cout << ch;
//			if (ch == '/')
//			{
//				break;
//			}
//			else
//			{
//				if (ch == '-')
//				{
//					count2++;
//				}
//				temp[count1] = ch;
//				count1++; //count1 for friends id count 
//			}
//
//		}
//		temp[count1] = '-';
//		count1++;
//		temp[count1] = '\0';
//		//cout << temp << endl;
//		count2 += 1;
//		//cout << count2 << endl;
//		FriendList = new  User * [count2];
//		for (i = 0;i < count2;i++)
//		{
//			FriendList[i] = new User();
//		}
//		int count3 = 0;
//		int j = 0;
//
//		for (i = 0; i < count1; i++)
//		{
//			if (temp[i] == '-')
//			{
//				FriendList[j]->id = new char[count3 + 1];
//				count3 = 0;
//				j++;
//			}
//			else
//			{
//				count3++;
//			}
//
//		}
//
//		j = 0;
//		int k = 0;
//		int l = 1;
//		for (i = 0;i < count1;i++)
//		{
//			if (temp[i] == '-')
//			{
//				FriendList[j]->id[k] = '\0';
//				cout << FriendList[j]->id << endl;
//				k = 0;
//				j++;
//
//			}
//			else
//			{
//				FriendList[j]->id[k] = temp[i];
//				k++;
//			}
//
//
//		}
//
//		int p;
//		ifstream read;
//		read.open("FriendList.txt", ios::in);
//		j = 0;
//		int check = 0;
//		if (read.is_open())
//		{
//			string s;
//			while (getline(read, s))
//			{
//				//cout << s << endl;
//
//				for (i = 0;s[i] != '\0';i++)
//				{
//					for (;s[i] != '-' && s[i] != '\0';i++)
//					{
//						if (FriendList[j]->id[i] == s[i])
//						{
//							check = 0;
//						}
//						else
//						{
//							check = 1;
//							break;
//						}
//					}
//					/*if (check==0)
//					{
//						i++;
//						count1 = 0;
//						for (;s[i]!='-'&&s[i]!='\0';i++)
//						{
//							count1++;
//						}
//						FriendList[j]->FName = new char[count1 + 1];
//						for (p = 0; p < count1; p++)
//						{
//							FriendList[j]->FName[p] = temp[p];
//						}
//						FriendList[j]->FName[p] = '\0';
//						cout << "Hmara Data "<<endl;
//						cout<<FriendList[j]->FName<<endl;
//						j++;
//					}*/
//					if (s[i] == '\0')
//					{
//						i--;
//					}
//					check = 0;
//
//				}
//
//			}
//			read.close();
//
//		}
//		else
//		{
//			cout << "file not";
//		}
//		for (i = 0; i < count2; i++)
//		{
//			//FriendList[i]->PrintFriendList();
//		}
//
//
//		count1 = 0;
//
//
//		while (!obj1.eof())
//		{
//			obj1 >> ch;
//			if (ch == ',')
//			{
//				break;
//			}
//			else
//			{
//				if (ch == '-')
//				{
//					count2++;
//				}
//				temp[count1] = ch;
//				count1++; //count1 for friends id count 
//			}
//
//		}
//		//FriendList = new User*[count2];
//
//		/*for (i=0;i<count2;i++)
//		{
//			FriendList[i] = new User(obj1);
//		}*/
//	}
//	delete[]temp;
//}















class User
{
private:
	char* userid;
	char* username;
	Friend* frd;
	int frdsize;
	Page* page;
	int pagesize;
	Activity* post;
	int postsize;
public:
	User()
	{
		frdsize = 0;
		pagesize = 0;
		postsize = 0;
		userid = nullptr;
		username = nullptr;
		frd = new Friend[10];
		page = new Page[10];
		post = new Activity[10];
	}
	User(const User& obj)
	{
		frdsize = obj.frdsize;
		pagesize = obj.pagesize;
		postsize = obj.postsize;
		copy(userid, obj.userid);
		copy(username, obj.username);
		for (int i = 0; i < frdsize; i++)
		{
			frd[i] = obj.frd[i];
		}
		for (int i = 0; i < pagesize; i++)
		{
			page[i] = obj.page[i];
		}
		for (int i = 0; i < postsize; i++)
		{
			post[i] = obj.post[i];
		}
	}
	void setuserid(char* _userid)
	{
		copy(userid, _userid);
	}
	char* getuserid()
	{
		char* ptr = nullptr;
		copy(ptr, userid);
		return ptr;
	}
	void setusername(char* _username)
	{
		copy(username, _username);
	}
	char* getusername()
	{
		char* ptr = nullptr;
		copy(ptr, username);
		return ptr;
	}
	void setfrd(Friend& obj, int temp)
	{
		frd[temp] = obj;
	}
	char* getfrdid(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, frd[temp].getfrdid());
		return ptr;
	}
	void setfrdname(char* _frdname, int temp)
	{
		if (frdsize < 10)
		{
			frd[temp].setfrdname(_frdname);
		}
	}
	void setfrdpageid(char* _pageid, int temp)
	{
		frd[temp].setfrdpageid(_pageid);
	}
	void setfrdpagetitle(char* _pagetitle, int temp)
	{
		frd[temp].setfrdpagetitle(_pagetitle);
	}
	char* getuserpageid(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, page[temp].getpageid());
		return ptr;
	}
	char* getuserfrdname(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, frd[temp].getfrdname());
		return ptr;
	}
	void setfrdpostid(char* _postid, int temp)
	{
		frd[temp].setfrdpostid(_postid);
	}
	void setfrdpostdate(int dt, int mon, int yr, int temp)
	{
		frd[temp].setfrdpostdate(dt, mon, yr);
	}
	void setfrdpostdesc(char* desc, int temp)
	{
		frd[temp].setfrdpostdesc(desc);
	}
	int getuserpostdate(int temp)
	{
		return post[temp].getpostdate();
	}
	int getuserpostmonth(int temp)
	{
		return post[temp].getpostmonth();
	}
	int getuserpostyear(int temp)
	{
		return post[temp].getpostyear();
	}
	char* getuserpostdesc(int temp)
	{
		return post[temp].getpostdesc();
	}
	void setfrdposttype(int type, int temp)
	{
		frd[temp].setfrdposttype(type);
	}
	void setfrdpostvalue(char* value, int temp)
	{
		frd[temp].setfrdpostvalue(value);
	}
	char* getfrdpostid(int temp, int tem)
	{
		char* ptr = nullptr;
		copy(ptr, frd[temp].getfrdpostid(tem));
		return ptr;
	}
	char* getuserpostid(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, post[temp].getpostid());
		return ptr;
	}
	int getpagesize()
	{
		return pagesize;
	}
	char* getpageid(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, page[temp].getpageid());
		return ptr;
	}
	char* getpagetitle(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, page[temp].getpagetitle());
		return ptr;
	}
	int getfrdsize()
	{
		return frdsize;
	}
	int getpostsize()
	{
		return postsize;
	}
	void setpostid(char* _postid)
	{
		post[postsize++].setpostid(_postid);
	}
	char* getshareid(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, post[temp].getshareid());
		return ptr;
	}
	void setpostdate(int dat, int mon, int yr)
	{
		post[postsize - 1].setfulldate(dat, mon, yr);
	}
	void setpostdesc(char* _postdesc)
	{
		post[postsize - 1].setdesc(_postdesc);
	}
	void setposttypeandvalue(int _type, char* _value)
	{
		post[postsize - 1].settype(_type);
		post[postsize - 1].setvalue(_value);
	}
	void setpostshare(char* _postid)
	{
		post[postsize - 1].setshareid(_postid);
		post[postsize - 1].setsharename(username);
	}
	void setpostlikeid(char* _likeid)
	{
		post[postsize - 1].setlikeid(_likeid);
	}
	void setpostlikename(char* _likename)
	{
		post[postsize - 1].setlikename(_likename);
	}

	void setfrdid(char* _frdid)
	{
		if (frdsize < 10)
		{
			frd[frdsize++].setfrdid(_frdid);
		}
	}

	void setpageid(char* _pageid)
	{
		if (pagesize < 10)
		{
			page[pagesize++].setpageid(_pageid);
		}
	}
	void setpagetitle(char* _pagetitle, int temp)
	{
		if (pagesize < 10)
		{
			page[temp].setpagetitle(_pagetitle);
		}
	}
	void displayfrd()
	{
		for (int i = 0; i < frdsize; i++)
		{
			frd[i].display();
		}
	}
	void displaypage()
	{

		for (int i = 0; i < pagesize; i++)
		{
			if (page != nullptr)
			{
				page[i].display();
			}
		}
	}
	void pagedisplaypost()
	{
		for (int j = 0; j < pagesize; j++)
		{
			page[j].pagedisplaypost();
		}

	}
	~User()
	{
		delete userid;
		delete username;
	}
	int gettype(int temp)
	{
		if (post[temp].gettype() != nullptr)
		{
			if (post[temp].gettype()[0] == 'f')// feeling
				return 1;
			else if (post[temp].gettype()[0] == 't')//thinking
				return 2;
			else if (post[temp].gettype()[0] == 'm')//making
				return 3;
			else if (post[temp].gettype()[0] == 'c')//celebrating
				return 4;
			else
				return 0;
		}
		return 0;
	}
	char* gettypechar(int temp)
	{
		char* ptr = nullptr;
		copy(ptr, post[temp].gettype());
		return ptr;
	}
	char* getvalue(int temp)
	{
		if (gettype(temp) > 0)
		{
			char* ptr = nullptr;
			copy(ptr, post[temp].getvalue());
			return ptr;
		}
		return nullptr;
	}
	void frddisplaypost()
	{
		for (int j = 0; j < frdsize; j++)
		{
			frd[j].displaypost();
		}
	}
	char* getpostid(int temp)
	{
		return post[temp].getpostid();
	}
	void userdisplaypost()
	{
		for (int j = 0; j < postsize; j++)
		{
			post[j].display(username);
		}
	}
	void copy(char*& ptr, const char* qtr)
	{
		int size = 0;
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			size++;
		}
		ptr = new char[size + 1];
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			ptr[i] = qtr[i];
		}
		ptr[size] = '\0';
	}
	bool cmp(char* ptr, char* qtr)
	{
		int size1 = 0, size2 = 0;
		for (int i = 0; i < ptr[i] != '\0'; i++)
		{
			size1++;
		}
		for (int i = 0; i < qtr[i] != '\0'; i++)
		{
			size2++;
		}
		if (size1 == size2)
		{
			for (int i = 0; i < ptr[i] != '\0'; i++)
			{
				if (ptr[i] != qtr[i])
				{
					return 1;
				}
			}
			return 0;
		}
		return 1;
	}
	void setpagepostid(char* _postid, int temp)
	{
		page[temp].setpagepostid(_postid);
	}
	void setpagepostdate(int dat, int mon, int yr, int temp)
	{
		page[temp].setpagepostdate(dat, mon, yr);
	}
	void setpagepostdesc(char* _postdesc, int temp)
	{
		page[temp].setpagepostdesc(_postdesc);
	}
	void setpageposttypeandvalue(int _type, char* _value, int temp)
	{
		page[temp].setpageposttypeandvalue(_type, _value);
	}
};

class Facebook/*SocialNetworkApp*/ :public User
{
private:
	User* user; //comment is already linked with user and activity so we dont need that here
	int totaluser;
	int currentuser;
	Page* page;
	int totalpg;
	Activity* post;
	int totalpst;
public:
	Facebook(void)
	{
	}
	~Facebook()
	{
		cout << "------------------------" << endl;
		cout << "Destructor Facebook App" << endl;
		cout << "------------------------" << endl;
	}
	void setCurrentUser(char* id, char* nam)
	{
		for (int i = 0; i < totaluser; i++)
		{
			if (cmp(user[i].getuserid(), id) == 0)
			{
				currentuser = i;
			}
		}
		cout << "Command: \t" << "Set current user \'" << id << "\'" << endl;
		cout << "------------------------------------------------" << endl;
		cout << nam << " successfully set as current user." << endl;
		cout << "\nCommand: \t" << "Set current system date: " << gettime() << endl;
	}
	void viewHomeOfCurrentUser()
	{
		cout << "\nCommand: \t" << "view Home: " << endl;
		cout << "------------------------------------------------" << endl;
		cout << user[currentuser].getusername() << "-- Home page" << endl;
		user[currentuser].frddisplaypost();
		user[currentuser].pagedisplaypost();
	}
	void likeAPost(const char* ptr)
	{
		cout << "\nCommand: \t" << "LikePost(" << ptr << ")" << endl;
		for (int i = 0; i < totalpst; i++)
		{
			if (cmp(post[i].getpostid(), ptr) == 0)
			{
				post[i].setlikeby(user[currentuser].getuserid(), user[currentuser].getusername());
			}
		}
	}
	void viewListOfPostLikedPeople()
	{

	}
	void commentOnAPost()
	{

	}
	void viewAPost(const char* ptr)
	{
		cout << "\nCommand: \t" << "Viewlikedlist(" << ptr << ")" << endl;
		cout << "------------------------------------------------" << endl;
		for (int i = 0; i < totalpst; i++)
		{
			if (post[i].getpostid() != nullptr)
			{
				if (cmp(post[i].getpostid(), ptr) == 0)
				{
					post[i].displaylikeby();
				}
			}
		}
	}
	void shareAPost(const char* ptr)
	{
		cout << "\nCommand: \t SharePost(" << ptr << ")" << endl;
	}
	void viewUserTimeline()
	{
		cout << "\nCommand: \t View TimeLine:" << endl;
		cout << "------------------------------------------------" << endl;
		cout << user[currentuser].getusername() << "--Time Line" << endl;
		user[currentuser].userdisplaypost();
	}
	void friendList()
	{
		cout << "\nCommand: \t" << "view friend list: " << endl;
		cout << "------------------------------------------------" << endl;
		cout << user[currentuser].getusername() << "--Friend List" << endl;
		user[currentuser].displayfrd();
	}

	void viewPage()
	{
		cout << "\nCommand: \t" << "view liked pages: " << endl;
		cout << "------------------------------------------------" << endl;
		cout << user[currentuser].getusername() << "--liked pages" << endl;
		user[currentuser].displaypage();
	}

	void viewPage(char* ptr)
	{
		cout << "\nCommand: \t" << "view page(" << ptr << ")" << endl;
		cout << "------------------------------------------------" << endl;
		for (int i = 0; i < totalpg; i++)
		{
			if (cmp(page[i].getpageid(), ptr) == 0)
			{
				cout << page[i].getpagetitle() << endl;
				for (int j = 0; j < page[i].getpostsize(); j++)
				{
					cout << page[i].getpagetitle() << " is " << page[i].getposttypechar(j) << " " << page[i].getpagepostvalue(j) << endl;
					cout << page[i].getpagepostdesc(j) << endl;
				}
			}
		}
	}

	void search(const char* ptr)
	{
		cout << "\nCommand: \t" << "Search(\"" << ptr << "\")" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Users: " << endl;
		for (int i = 0; i < totaluser; i++)
		{
			if (match(user[i].getusername(), ptr) == 0)
			{
				cout << "\t" << user[i].getuserid() << "-" << user[i].getusername() << endl;
			}
		}
		cout << "Posts:" << endl;
		for (int i = 0; i < totaluser; i++)
		{
			for (int j = 0; j < user[i].getpostsize(); j++)
			{
				if (match(user[i].getuserpostdesc(j), ptr) == 0)
				{
					cout << user[i].getuserpostid(j) << "-" << user[i].getusername() << " is " << user[i].gettypechar(j) << " " << user[i].getvalue(j) << endl;
					cout << "\t\"" << user[i].getuserpostdesc(j) << "\"" << endl;
				}
			}
		}
		cout << "Pages: " << endl;
		for (int i = 0; i < totalpg; i++)
		{
			if (match(page[i].getpagetitle(), ptr) == 0)
			{
				cout << "\t" << page[i].getpageid() << "-" << page[i].getpagetitle() << endl;
			}
		}
	}
	void Run()
	{
		char garb[200];
		ifstream fin;

		fin.open("FacebookPages.txt");
		char pgid[10];
		char pgtitle[60];
		fin >> totalpg;
		page = new Page[totalpg]; //array of objects (dynamic array)
		for (int i = 0; i < totalpg; i++)
		{
			fin >> pgid;
			fin.getline(pgtitle, 60, '\n');
			page[i].setpageid(pgid);
			page[i].setpagetitle(pgtitle);
		}
		fin.close();



		char userid[10];
		char fstname[20];
		char lstname[20];
		char frdid[10];

		fin.open("user.txt");
		fin >> totaluser;
		user = new User[totaluser];
		for (int i = 0; i < totaluser; i++)
		{
			fin >> userid;
			user[i].setuserid(userid);
			fin >> fstname;
			fin >> lstname;

			user[i].setusername(join(fstname, lstname));
			while (true)
			{
				fin >> frdid; // friend's pointer is in user's class ....association
				if (cmp(frdid, "-1") != 0) {

					user[i].setfrdid(frdid);
				}
				else
					break;
			}
			while (true)
			{
				fin >> pgid;
				if (cmp(pgid, "-1") != 0) {

					user[i].setpageid(pgid);
				}
				else

					break;
			}

		}
		fin.close();

		for (int j = 0; j < totaluser; j++)
		{
			for (int k = 0; k < user[j].getpagesize(); k++)
			{
				for (int i = 0; i < totalpg; i++)
				{
					if (cmp(user[j].getpageid(k), page[i].getpageid()) == 0)
					{
						user[j].setpagetitle(page[i].getpagetitle(), k);
					}
				}
			}
		}


		for (int i = 0; i < totaluser; i++)
		{
			for (int k = 0; k < totaluser; k++)
			{
				for (int j = 0; j < user[k].getfrdsize(); j++)
				{
					if (cmp(user[k].getfrdid(j), user[i].getuserid()) == 0)
					{
						user[k].setfrdname(user[i].getusername(), j);
					}
				}
			}
		}

		fin.open("Post.txt");
		char postid[10];
		int dt, mon, yr, likeindex = 0;
		char postdesc[200];
		int type, type_1;
		char value[40], share[10], like[10];

		fin >> totalpst;
		post = new Activity[totalpst];


		int k = 0;
		for (int i = 0; i < totalpst; i++)
		{
			fin >> type_1;
			fin >> postid;
			fin >> dt >> mon >> yr;
			fin.ignore();
			fin.getline(postdesc, 200, '\n');
			if (type_1 == 2)
			{
				fin >> type;

				if (type > 0)
				{
					fin.getline(value, 40, '\n');
				}
			}
			fin >> share;

			if (share[0] == 'u')
			{

				for (int j = 0; j < totaluser; j++)
				{
					if (cmp(user[j].getuserid(), share) == 0) {
						k = j;
						break;
					}
				}
				user[k].setpostid(postid);
				user[k].setpostdate(dt, mon, yr);
				user[k].setpostdesc(postdesc);
				user[k].setpostshare(share);
				post[i].setpostid(postid);
				post[i].setfulldate(dt, mon, yr);
				post[i].setdesc(postdesc);
				if (type > 0)
				{
					user[k].setposttypeandvalue(type, value);
				}
				while (true)
				{
					fin >> like;
					if (cmp(like, "-1") != 0) {
						user[k].setpostlikeid(like);
						if (like[0] == 'u')
						{
							for (int j = 0; j < totaluser; j++)
							{
								if (cmp(user[j].getuserid(), like) == 0)
								{
									user[k].setpostlikename(user[j].getusername());
									post[i].setlikeby(like, user[j].getusername());
									break;
								}
							}
						}
						else
						{
							for (int j = 0; j < totalpg; j++)
							{
								if (cmp(page[j].getpageid(), like) == 0)
								{
									user[k].setpostlikename(page[j].getpagetitle());
									post[i].setlikeby(like, page[j].getpagetitle());
									break;
								}
							}
						}
					}
					else
						break;
				}
			}
			else
			{
				for (int j = 0; j < totalpg; j++)
				{
					if (cmp(page[j].getpageid(), share) == 0) {
						k = j;
						break;
					}
				}
				page[k].setpagepostid(postid);
				page[k].setpagepostdate(dt, mon, yr);
				page[k].setpagepostdesc(postdesc);
				page[k].setpagepostshare(share);
				post[i].setpostid(postid);
				post[i].setfulldate(dt, mon, yr);
				post[i].setdesc(postdesc);
				if (type > 0)
				{
					page[k].setpageposttypeandvalue(type, value);
				}
				while (true)
				{
					fin >> like;
					if (cmp(like, "-1") != 0) {
						page[k].setpostlikeid(like);
						if (like[0] == 'u')
						{
							for (int j = 0; j < totaluser; j++)
							{
								if (cmp(user[j].getuserid(), like) == 0)
								{
									page[k].setpostlikename(user[j].getusername());
									post[i].setlikeby(like, user[j].getusername());
									break;
								}
							}
						}
						else
						{
							for (int j = 0; j < totalpg; j++)
							{
								if (cmp(page[j].getpageid(), like) == 0)
								{
									page[k].setpostlikename(page[j].getpagetitle());
									post[i].setlikeby(like, page[j].getpagetitle());
									break;
								}
							}
						}
					}
					else
						break;
				}
			}


		}
		fin.close();


		for (int i = 0; i < totaluser; i++)
		{
			for (int j = 0; j < user[i].getpostsize(); j++)
			{
				for (int k = 0; k < totaluser; k++)
				{
					for (int l = 0; l < user[k].getfrdsize(); l++)
					{
						if (cmp(user[k].getfrdid(l), user[i].getuserid()) == 0)
						{
							user[k].setfrdpostid(user[i].getuserpostid(j), l);
							user[k].setfrdpostdate(user[i].getuserpostdate(j), user[i].getuserpostmonth(j), user[i].getuserpostyear(j), l);
							user[k].setfrdpostdesc(user[i].getuserpostdesc(j), l);

							if (user[i].gettype(j) > 0)
							{
								user[k].setfrdposttype(user[i].gettype(j), l);
								user[k].setfrdpostvalue(user[i].getvalue(j), l);
							}
							break;
						}
					}
				}
			}
		}


		for (int i = 0; i < totalpg; i++)
		{
			for (int j = 0; j < page[i].getpostsize(); j++)
			{
				for (int k = 0; k < totaluser; k++)
				{
					for (int l = 0; l < user[k].getpagesize(); l++)
					{
						if (cmp(user[k].getpageid(l), page[i].getpageid()) == 0)
						{
							user[k].setpagepostid(page[i].getpagepostid(j), l);
							user[k].setpagepostdate(page[i].getpagepostdate(j), page[i].getpagepostmonth(j), page[i].getpagepostyear(j), l);
							user[k].setpagepostdesc(page[i].getpagepostdesc(j), l);

							if (page[i].getpageposttype(j) > 0)
							{
								user[k].setpageposttypeandvalue(page[i].getpageposttype(j), page[i].getpagepostvalue(j), l);
							}
							break;
						}
					}
				}
			}
		}


		fin.open("comments.txt");
		int totalcomment = 0;
		char commentid[10];
		char commenttext[60];

		fin >> totalcomment;
		fin.getline(garb, 200, '\n');
		for (int i = 0; i < totalcomment; i++)
		{
			fin >> commentid >> postid >> userid;
			fin.ignore();
			fin.getline(commenttext, 60, '\n');

		}



		cout << "\t\tWELCOME!" << endl;
		char id[] = "u7";

		char nam[] = "Abdullah Nadeem";
		setCurrentUser(id, nam);

		friendList();

		viewPage();

		viewHomeOfCurrentUser();

		viewUserTimeline();

		likeAPost("post6");

		viewAPost("post6");

		shareAPost("post5");

		search("Birthday");

		search("Ali");

		cout << endl;
	}

	bool cmp(char* ptr, const char* qtr)
	{
		int size1 = 0, size2 = 0;
		for (int i = 0; i < ptr[i] != '\0'; i++)
		{
			size1++;
		}
		for (int i = 0; i < qtr[i] != '\0'; i++)
		{
			size2++;
		}
		if (size1 == size2)
		{
			for (int i = 0; i < ptr[i] != '\0'; i++)
			{
				if (ptr[i] != qtr[i])
				{
					return 1;
				}
			}
			return 0;
		}
		return 1;
	}
	char* join(char* ptr, char* qtr)
	{
		int size1 = 0, size2 = 0;
		for (int i = 0; i < ptr[i] != '\0'; i++)
		{
			size1++;
		}
		for (int i = 0; i < qtr[i] != '\0'; i++)
		{
			size2++;
		}
		char* arr = new char[size1 + size2]();
		for (int i = 0; i < ptr[i] != '\0'; i++)
		{
			arr[i] = ptr[i];
		}
		arr[size1++] = ' ';
		for (int i = 0; i < qtr[i] != '\0'; i++)
		{
			arr[size1++] = qtr[i];
		}
		arr[size1] = '\0';
		return arr;
	}
	char*& gettime()
	{
		time_t t;
		int size = 26, size2 = 0;
		char yr[12][5] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		char* date = new char[26];
		time(&t);
		ctime_s(date, size, &t);
		for (int i = 0; i < size - 4; i++) {
			date[i] = date[i + 4];
		}
		size = size - 4;
		date[size] = '\0';

		for (int i = 7; i < size - 9; i++) {
			date[i] = date[i + 9];
		}
		size = size - 9;
		date[size] = '\0';

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 3; j++) {
				if (date[j] == yr[i][j])
				{
					size2++;
				}
			}
			if (size2 == 3)
			{
				for (int k = 0; k < size; k++) {
					date[k] = date[k + 1];
				}
				size--;
				if (i < 9)
				{
					date[0] = 48;
					date[1] = (i + 1) + 48;
				}
				else
				{
					date[0] = ((i + 1) / 10) + 48;
					date[1] = ((i + 1) % 10) + 48;
				}
			}
			size2 = 0;
		}
		return date;
	}
	void deepcopy(char*& ptr, char* qtr)
	{
		int size = 0;
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			size++;
		}
		ptr = new char[size + 1];
		for (int i = 0; qtr[i] != '\0'; i++)
		{
			ptr[i] = qtr[i];
		}
		ptr[size] = '\0';
	}

	bool match(char* ptr, const char* qtr)
	{
		int space = 0, k = 0, index = 0;
		bool flag = 0;
		for (int i = 0; ptr[i] != '\0'; i++)
		{
			if (ptr[i] == ' ')
			{
				space++;
			}
		}
		while (space != 0)
		{
			for (int i = k; ptr[i] != ' ' && qtr[index] != '\0'; i++, index++)
			{
				if (ptr[i] != qtr[index])
				{
					flag = 1;
				}
			}

			for (; ptr[k] != ' '; k++) {}

			if (flag == 0)
			{
				return 0;
			}
			flag = 0;
			index = 0;
			space--;
			k++;
		}

		for (int i = 0; ptr[k] != '\0' && qtr[i] != '\0'; i++, k++)
		{
			if (ptr[k] != qtr[i])
			{
				return 1;
			}
		}
		return 0;
	}
};
int main()
{
	//int k1 = 0;
	//User** ptr;

	//int count;
	//ifstream obj;
	//obj.open("FriendList.txt");  reading data from file 
	//if (obj)
	//{
	//	obj >> count;
	//	count -= 1;
	//	ptr = new User * [count];
	//	for (int i = 0; i < count; i++)
	//	{
	//		ptr[i] = new User(obj);
	//	}
	//	for (int i = 0; i < count; i++)
	//	{
	//		cout << "data " << i + 1 << endl;
	//		//ptr[i]->print();
	//		cout << endl;
	//	}
	//}

	//else
	//{
	//	cout << "not";
	//}


	Facebook obj;
	obj.Run();


	cout << "Coding Mubarak ";
	system("pause");
	return 0;
}

