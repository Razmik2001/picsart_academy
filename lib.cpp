#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
typedef unsigned int UI;

class Material
{
protected:
    string title = "NONE";
    bool isBorrowed = false;
    Material() = default;
public:
    virtual void getInfo() = 0;
    virtual string getTitle() = 0;
    virtual ~Material() = default;
    void take();
    void replace();
};

void Material::take()
{
    if (!isBorrowed)
    {
        isBorrowed = true;
    }
    else
    {
        cout << "This material is not in the library now" << endl;
    }
}

void Material::replace()
{
    if (isBorrowed)
    {
        isBorrowed = false;
    }
    else
    {
        cout << "This material is now in the library" << endl;
    }
}

class Book : public Material
{
private:
    string author = "NONE";
    UI publishYear = 0;
    string genre = "NONE";
    UI numberOfPages = 0;
public:
    Book(string T, string A, UI PY, string G, UI NOP);
    string getTitle() override { return title; }
    void getInfo() override;
};

Book::Book(string T, string A, UI PY, string G, UI NOP)
{
    try
    {
        if (PY > 2023)
        {
            throw std::invalid_argument("You can't have a book from the future");
        }
        title = T;
        author = A;
        publishYear = PY;
        genre = G;
        numberOfPages = NOP;
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

void Book::getInfo()
{
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publish Year: " << publishYear << endl;
    cout << "Genre: " << genre << endl;
    cout << "Number of Pages: " << numberOfPages << endl;
    if (!isBorrowed)
    {
        cout << "This material is now in the library" << endl; 
    }
    else
    {
        cout << "This material is not in the library now" << endl;
    }
}

class Journal : public Material
{
private:
    UI volume = 0;
    UI issue = 0;
    UI publishYear = 0;
    string subject = "NONE";
public:
    Journal(string T, UI V, UI I, UI PY, string S);
    string getTitle() override { return title; }
    void getInfo() override;
};

Journal::Journal(string T, UI V, UI I, UI PY, string S)
{
    try
    {
        if (PY > 2023)
        {
            throw std::invalid_argument("You can't have a journal from the future");
        }
        else if (I == 0)
        {
            throw std::invalid_argument("You must have at least one issue");
        }
        title = T;
        volume = V;
        publishYear = PY;
        issue = I;
        subject = S;
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

void Journal::getInfo()
{
    cout << "Title: " << title << endl;
    cout << "Volume: " << volume << endl;
    cout << "Issue: " << issue << endl;
    cout << "Publish Year: " << publishYear << endl;
    if (!isBorrowed)
    {
        cout << "This material is now in the library" << endl; 
    }
    else
    {
        cout << "This material is not in the library now" << endl;
    }
}

class DVD : public Material
{
private:
    UI releaseYear = 0;
    string director = "NONE";
    double duration = 0;
public:
    DVD(string T, UI RY, string Dir, double Dur);
    string getTitle() override { return title; }
    void getInfo() override;
};

DVD::DVD(string T, UI RY, string Dir, double Dur)
{
    try
    {
        if (RY > 2023)
        {
            throw std::invalid_argument("You can't have a DVD from the future");
        }
        else if (Dur <= 0)
        {
            throw std::invalid_argument("Duration cannot be less than or equal to 0 minutes");
        }
        title = T;
        releaseYear = RY;
        director = Dir;
        duration = Dur;
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

void DVD::getInfo()
{
    cout << "Title: " << title << endl;
    cout << "Release Year: " << releaseYear << endl;
    cout << "Director: " << director << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    if (!isBorrowed)
    {
        cout << "This material is now in the library" << endl; 
    }
    else
    {
        cout << "This material is not in the library now" << endl;
    }
}


class Library
{
private:
    vector<Material*> materials;
public:
    Library() = default;
    void addBook(string T, string A, UI PY, string G, UI NOP);
    void addJournal(string T, UI V, UI I, UI PY, string S);
    void addDVD(string T, UI RY, string Dir, double Dur);
    void takeMaterial(string title);
    void replaceMaterial(string title);
    ~Library();
    void find(string title);
};

void Library::takeMaterial(string title)
{
    for (auto it = materials.begin(); it != materials.end(); ++it)
    {
        if ((*it)->getTitle() == title)
        {
            (*it)->take();
            return;
        }
        cout << "we don't have this material" << endl;
    }
}

void Library::replaceMaterial(string title)
{
    for (auto it = materials.begin(); it != materials.end(); ++it)
    {
        if ((*it)->getTitle() == title)
        {
            (*it)->replace();
            return;
        }        
    }
    cout << "This is not our material" << endl;
}

void Library::addDVD(string T, UI RY, string Dir, double Dur)
{
        Material* s = new DVD(T, RY, Dir, Dur);
        materials.push_back(s);
}

void Library::addJournal(string T, UI V, UI I, UI PY, string S)
{
        Material* s = new Journal(T, V, I, PY, S);
        materials.push_back(s);
}

void Library::addBook(string T, string A, UI PY, string G, UI NOP)
{
        Material* s = new Book(T, A, PY, G, NOP);
        materials.push_back(s);
}

void Library::find(string title)
{
    for (auto it = materials.begin(); it != materials.end(); ++it)
    {
        if ((*it)->getTitle() == title)
        {
            (*it)->getInfo();
            return;
        }
    }
    cout << "We don't have a material with that name" << endl;
}

Library::~Library()
{
    for (auto it = materials.begin(); it != materials.end(); ++it)
    {
        delete *it;
    }
}

int main()
{
    Library lib;

    // Adding materials
    lib.addBook("Book", "Author 1", 2022, "Genre 1", 200);
    lib.addJournal("Journal", 1, 1, 2022, "Subject 1");
    lib.addDVD("DVD", 2022, "Director 1", 120);

    // Finding a material
    string title;
    cout << "Enter the title of the material you want to find: ";
    cin >> title;
    lib.find(title);

    // Taking and replacing materials
    cout << "Enter the title of the material you want to take: ";
    cin >> title;
    lib.takeMaterial(title);

    cout << "Enter the title of the material you want to replace: ";
    cin >> title;
    lib.replaceMaterial(title);

    // Displaying information
    lib.find("Book");

    return 0;
}
