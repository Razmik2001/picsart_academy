#include <iostream>
#include <string>
#include <vector>

#include <cstring>

bool isDouble(std::string temp)
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
    std::string m_value;
public:
    int toInt();
    double toDouble();
    std::string toString() { return m_value; }
    template <class T>
    void setValue(T value);
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

int Cell::toInt()
{
    try
    {
        for (int i = 0; i < m_value.length(); ++i)
        {
            if (!isdigit(m_value[i]))
                throw std::invalid_argument("value is not int;");
        }
        return atoi(m_value.c_str());
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}

double Cell::toDouble()
{
    try
    {
        if (isDouble(m_value))
        {
            return atof(m_value.c_str());
        }
        throw std::invalid_argument("value is not double;");
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}

class Spreadsheet
{
    std::vector<std::vector<Cell>> m_cells;
public:
    Spreadsheet(unsigned int row, unsigned int cal)
    {
        m_cells.resize(row);
        for (int i = 0; i < row; i++)
            m_cells[i].resize(cal);
    }
    void setCellAt(int row, int cal, std::string str);
    void setCellAt(int row, int cal, Cell* cell);
    void addRow(int row);
    void addColumn(int cal);
    Cell* getCellAt(int row, int cal);
};

void Spreadsheet::setCellAt(int row,int cal,Cell* cell)
{
	try
	{
		if (row >= m_cells.size() || cal >= m_cells[0].size())
			throw std::invalid_argument("I don't have a cell with these coordinates;");
		m_cells[row][cal].setValue(cell->toString());
	}
	catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

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

Cell*  Spreadsheet::getCellAt(int row, int cal)
{
    try
    {
        if (row >= m_cells.size() || cal >= m_cells[0].size())
            throw std::invalid_argument("I don't have a cell with these coordinates;");
        return &m_cells[row][cal];
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

void Spreadsheet::setCellAt(int row, int cal, std::string str)
{
    try
    {
        if (row >= m_cells.size() || cal >= m_cells[0].size())
            throw std::invalid_argument("I don't have a cell with these coordinates;");
        m_cells[row][cal].setValue(str);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

int main() {
    // Create a new spreadsheet with 3 rows and 4 columns
    Spreadsheet spreadsheet(3, 4);

    // Set values in cells
    spreadsheet.setCellAt(0, 0, "10");
    spreadsheet.setCellAt(1, 1, "3.14");
    spreadsheet.setCellAt(2, 2, "Hello");

    // Access and test cell values
    Cell* cell1 = spreadsheet.getCellAt(0, 0);
    Cell* cell2 = spreadsheet.getCellAt(1, 1);
    Cell* cell3 = spreadsheet.getCellAt(2, 2);

    std::cout << "Cell 1: " << cell1->toInt() << std::endl;
    std::cout << "Cell 2: " << cell2->toDouble() << std::endl;
    std::cout << "Cell 3: " << cell3->toString() << std::endl;

    // Add a new row and column
    spreadsheet.addRow(2);
    spreadsheet.addColumn(3);

    // Set values in the newly added cells
    spreadsheet.setCellAt(3, 0, "20");
    spreadsheet.setCellAt(4, 3, "3.14159");
    spreadsheet.setCellAt(4, 2, "World");

    // Access and test the new cell values
    Cell* newCell1 = spreadsheet.getCellAt(3, 0);
    Cell* newCell2 = spreadsheet.getCellAt(4, 3);
    Cell* newCell3 = spreadsheet.getCellAt(4, 2);

    std::cout << "New Cell 1: " << newCell1->toInt() << std::endl;
    std::cout << "New Cell 2: " << newCell2->toDouble() << std::endl;
    std::cout << "New Cell 3: " << newCell3->toString() << std::endl;

    // Set a cell using another cell's value
    spreadsheet.setCellAt(3, 1, newCell2);

    // Access and test the updated cell value
    Cell* updatedCell = spreadsheet.getCellAt(3, 1);
    std::cout << "Updated Cell: " << updatedCell->toDouble() << std::endl;

    // Try setting a cell with invalid coordinates
    spreadsheet.setCellAt(6, 2, "Invalid"); // This should print an error message

    return 0;
}
