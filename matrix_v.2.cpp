#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <memory>

bool isDouble(const std::string& temp)
{
  int   j;
  int count;
  int not_zero = 0;
  
  count = 0;
    j = 0;
    if (strcmp(temp.c_str(), "0") == 0)
        return (1);
    if (temp[j] == '+' || temp[j] == '-')
        j++;
    if (j == 1 && (temp[j] == '\0' || temp[j] == '0'))
        return (0);
    if (temp[j] == '0' && temp[j + 1] != '\0' && temp[j + 1] != '.') 
        return (0);
    while (temp[j])
    {
    if (temp[j] > '0' && temp[j] <= '9')
          not_zero++;
        if (temp[j] < '0' || temp[j] > '9')
        {
            if (temp[j] == '.' && count == 0)
                count ++;
        else
                return (0);
        }
     if (temp[j + 1] == '\0' && temp[j] == '.')
                return (0);
        j++;
    }
  if (not_zero == 0)
    return 0;
    return (1);
}


class Cell
{
protected:
    std::string m_value;
public:
	template <class T>
    void setValue(T value);
    std::string getValue(){return m_value;};
};

template <class T>
void Cell::setValue(T value)
{
    if constexpr (std::is_same_v<T, int> || std::is_same_v<T, double>) {
        m_value = std::to_string(value);
    } else if constexpr (std::is_same_v<T, std::string>) {
        m_value = value;
    }
    else
    {
        try
        {
            throw std::invalid_argument("value must be double, int, or string;");
        }
        catch (std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}


class IntCell:public Cell
{
public:
	int toInt();
	template <class T>
    void setValue(T value);
	int getValue() 
	{
		return toInt();
	}
};


template <class T>
void IntCell::setValue(T value)
{
    if constexpr (std::is_same_v<T, int>) {
        m_value = std::to_string(value);
    }
    else
    {
        try
        {
            throw std::invalid_argument("value must be int;");
        }
        catch (std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

int IntCell::toInt()
{
    try
    {
        for (int i = 0; i < m_value.length(); ++i)
        {
            if (!isdigit(m_value[i]))
                throw std::invalid_argument("value is not int;");
        }
        return std::stoi(m_value.c_str());
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}

class DoubleCell:public Cell
{
public:
	double toDouble();
	template <class T>
    void setValue(T value);
	int getValue()  {return toDouble();}
	
};


template <class T>	 
void DoubleCell::setValue(T value)
{
    if constexpr (std::is_same_v<T, double>) {
        m_value = std::to_string(value);
    }
    else
    {
        try
        {
            throw std::invalid_argument("value must be double");
        }
        catch (std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

double DoubleCell::toDouble()
{
    try
    {
        if (isDouble(m_value))
        {
            return std::stof(m_value.c_str());
        }
        throw std::invalid_argument("value is not double;");
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}

class StringCell : public Cell{
public:
	template<class T>
	void setValue(T value)
	{
    if constexpr (std::is_same_v<T, std::string>) {
        m_value = value;
    }
    else
    {
        try
        {
            throw std::invalid_argument("value must be string;");
        }
        catch (std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}
};

class Spreadsheet
{
    std::vector<std::vector<std::unique_ptr<Cell>>> m_cells;
public:
    Spreadsheet(unsigned int row, unsigned int cal)
    {
        m_cells.resize(row);
        for (int i = 0; i < row; i++)
            m_cells[i].resize(cal);
    }//+
    void setCellAt(int row, int cal, std::string value);
    void setCellAt(int row, int cal, int value);
    void setCellAt(int row, int cal, double value);
    void setCellAt(int row, int cal, Cell* cell);
    void addRow(int row);//+
    void addColumn(int cal);//+
    std::unique_ptr<Cell> getCellAt(int row, int cal);//+
};

void Spreadsheet::addRow(int row)
{
    int oldRow =m_cells.size();
    row += oldRow;
    int cal = m_cells[0].size();
    m_cells.resize(row);
    for(int i = oldRow; i < row; ++i)
        m_cells[i].resize(cal);
}

void Spreadsheet::addColumn(int cal)
{
    int oldCol =m_cells[0].size();
    cal += oldCol;
    int row = m_cells.size();
    for(int i = 0; i < row; ++i)
        m_cells[i].resize(cal);
}

std::unique_ptr<Cell>  Spreadsheet::getCellAt(int row, int cal)
{
    try
    {
        if (row >= m_cells.size() || cal >= m_cells[0].size())
            throw std::invalid_argument("I don't have a cell with these coordinates;");
        return  std::move(m_cells[row][cal]);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

void Spreadsheet::setCellAt(int row, int cal, std::string value)
{
    try{
    	if (row >= m_cells.size() || cal >= m_cells[0].size())
        	throw std::invalid_argument("Invalid cell coordinates");
	    m_cells[row][cal] = std::make_unique<StringCell>();
    	m_cells[row][cal]->setValue(value);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

void Spreadsheet::setCellAt(int row, int cal, int value)
{
	try{
    	if (row >= m_cells.size() || cal >= m_cells[0].size())
        	throw std::invalid_argument("Invalid cell coordinates");
	    m_cells[row][cal] = std::make_unique<IntCell>();
    	m_cells[row][cal]->setValue(value);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

void Spreadsheet::setCellAt(int row, int cal, double value)
{
	try{
    	if (row >= m_cells.size() || cal >= m_cells[0].size())
        	throw std::invalid_argument("Invalid cell coordinates");
	    m_cells[row][cal] = std::make_unique<DoubleCell>();
    	m_cells[row][cal]->setValue(value);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}


void Spreadsheet::setCellAt(int row, int cal, Cell *cell)
{
	try {
    	if (row >= m_cells.size() || cal >= m_cells[0].size())
    	    throw std::invalid_argument("Invalid cell coordinates");
    	m_cells[row][cal].reset(cell);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

int main() {
    Spreadsheet spreadsheet(3, 4);	

    spreadsheet.setCellAt(0, 0, "Hello");
    std::unique_ptr<Cell> cell1 = spreadsheet.getCellAt(0, 0);
    std::cout << "Cell (0, 0): " << cell1->getValue() << std::endl;

	spreadsheet.setCellAt(1, 1, 42);
    std::unique_ptr<Cell> cell2 = spreadsheet.getCellAt(1, 1);
    std::cout << "Cell (1, 1): " << cell2->getValue() << std::endl;

    spreadsheet.setCellAt(2, 2, 3.14);
    std::unique_ptr<Cell> cell3 = spreadsheet.getCellAt(2, 2);
    std::cout << "Cell (2, 2): " << cell3->getValue() << std::endl;

    auto I =  new IntCell();
    I->setValue(17.5);
    spreadsheet.setCellAt(0, 3,I);
    std::unique_ptr<Cell> cell4 = spreadsheet.getCellAt(0, 3);
    std::cout << "Cell (0, 3): " << cell4->getValue() << std::endl;

	auto  D =  new DoubleCell();
    D->setValue("17");
    spreadsheet.setCellAt(1, 3,D);
	std::unique_ptr<Cell> cell5 = spreadsheet.getCellAt(1, 3);
    std::cout << "Cell (1, 3): " << cell5->getValue() << std::endl;

  	auto S =  new StringCell();
    S->setValue(5);
    spreadsheet.setCellAt(2, 3,S);
  	std::unique_ptr<Cell> cell6 = spreadsheet.getCellAt(2, 3);
    std::cout << "Cell (2, 3): " << cell6->getValue() << std::endl;

    spreadsheet.addRow(4);
    spreadsheet.addColumn(5);

    spreadsheet.setCellAt(3, 4, "World");

    std::unique_ptr<Cell> cell7 = spreadsheet.getCellAt(3, 4);
    std::cout << "Cell (3, 4): " << cell7->getValue() << std::endl;

    return 0;
}
