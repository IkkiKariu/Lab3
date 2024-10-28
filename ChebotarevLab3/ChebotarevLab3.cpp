#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void read()
{
    ifstream ifile;
    ifile.open("binar.txt");

    if (!ifile)
    {
        cout << "couldn`t open the file";
        return;
    }

    int x = 0;
    double y = 0;

    ifile.read((char*)&x, sizeof(x));
    ifile.read((char*)&y, sizeof(y));

    ifile.close();

    cout << x << endl;
    cout << y << endl;

    return;
}

void write()
{
    ofstream ofile;
    ofile.open("binar.txt", ios::binary);

    if (!ofile)
    {
        cout << "couldn`t open the file";
        return;
    }

    int x = 100;
    double y = 5.998;

    ofile.write((char*)&x, sizeof(x));
    ofile.write((char*)&y, sizeof(y));

    ofile.close();

    return;
}

void completeFirst()
{
    // Файловая переменная для исходного текстового файла
    ifstream ifile;
    ifile.open("firstTaskInput.txt");

    if (!ifile)
    {
        cout << "couldn`t open input file" << endl;
        return;
    }

    // Файловая переменная для результирующего бинарного файла
    ofstream ofile;
    ofile.open("firstTaskOutput.txt", ios::binary);

    if (!ofile)
    {
        cout << "couldn`t open output file" << endl;
        return;
    }

    int n = 0;

    // Считывание всех чисел из исходного файла с последующей записью в результирующий файл
    while (!ifile.eof())
    {
        ifile >> n;

        ofile.write((char*)&n, sizeof(n));
    }

    ifile.close();
    ofile.close();
    ofile.clear();

    // Открытие результирующего бинарного файла в режиме чтения
    ifstream resFile;
    resFile.open("firstTaskOutput.txt", ios::binary);

    if (!resFile)
    {
        cout << "couldn`t open output file" << endl;
        return;
    }
    
    // Чтение из результирующего бинарного файла
    while (!resFile.eof())
    {
        resFile.read((char*)&n, sizeof(n));

        cout << n << endl;
    }
    resFile.close();
    
    return;

    // *по неизвестной мне причине фукция выводит последнее число два раза 
}

void initSecond()
{
    const int arrLength = 5;
    int nums[arrLength] = { 123456, 176, 2147483647, 123, 12345 };

    ofstream ofile;
    ofile.open("secondTaskInput.txt", ios::binary);

    for (int i = 0; i < arrLength; i++)
    {
        ofile.write((char*)&(nums[i]), sizeof(nums[i]));
    }

    ofile.close();
}

void completeSecond()
{
    int k = 3;
    int n = 0;
    streampos kPosition = sizeof(n) * (k - 1);

    ifstream ifile;

    ifile.open("secondTaskInput.txt", ios::binary);

    if (!ifile)
    {
        cout << "couldn`t open input file" << endl;
        return;
    }

    ifile.seekg(kPosition);
    if (ifile.read((char*)&n, sizeof(n)))
    {
        cout << n << endl;
    }
    else 
    {
        cout << -1 << endl;
    }
    
    ifile.close();

    return;
}

void initThird()
{
    const int arrLength = 5;
    int nums[arrLength] = { 123456, 176, 2147483647, 123, 2292};

    ofstream ofile;
    ofile.open("thirdTaskInput.txt", ios::binary);

    for (int i = 0; i < arrLength; i++)
    {
        ofile.write((char*)&(nums[i]), sizeof(nums[i]));
    }

    ofile.close();
}

void completeThird()
{
    int num = 0, count = 0, firstNum = 0, secondNum = 0, penultNum = 0, lastNum = 0;

    ifstream ifile;
    ifile.open("thirdTaskInput.txt", ios::binary);

    if (!ifile)
    {
        cout << "couldn`t open input file" << endl;
        return;
    }

    while (ifile.read((char*)&num, sizeof(num)))
    {
        count++;

        if (count == 1)
        {
            firstNum = num;
        }
        else if (count == 2)
        {
            secondNum = num;
        }
        else
        {
            penultNum = lastNum;
            lastNum = num;
        }
    }

    ifile.close();

    cout << "Первое число: " << firstNum << endl;
    cout << "Второе число: " << secondNum << endl;
    cout << "Предпоследнее число: " << penultNum << endl;
    cout << "Последнее число: " << lastNum << endl;

    return;
}

void initFourth()
{
    const int arrLength = 5;
    int nums[arrLength] = { 1, 2, 3, 4, 5 };

    ofstream ofile;
    ofile.open("fourthTaskInput.txt", ios::binary);

    for (int i = 0; i < arrLength; i++)
    {
        ofile.write((char*)&(nums[i]), sizeof(nums[i]));
    }

    ofile.close();
}

void rec(ifstream &ifile, ofstream &ofile)
{
    int number;

    ifile.read((char*)&number, sizeof(number));

    if (ifile.eof())
    {
        return;
    }

    rec(ifile, ofile);

    ofile.write((char*)&number, sizeof(number));

    return;
}

void completeFourth()
{
    ifstream ifile;
    ifile.open("fourthTaskInput.txt", ios::binary);
    if (!ifile)
    {
        cout << "couldn`t open input file" << endl;
        return;
    }

    ofstream ofile;
    ofile.open("fourthTaskOutput.txt", ios::binary);
    if (!ifile)
    {
        cout << "couldn`t open output file" << endl;
        return;
    }

    rec(ifile, ofile);

    ifile.close();
    ofile.close();
    ofile.clear();

    ifstream resFile;
    resFile.open("fourthTaskOutput.txt", ios::binary);
    if (!resFile)
    {
        cout << "couldn`t open result file" << endl;
        return;
    }

    int number = 0;

    while (!resFile.eof())
    {
        resFile.read((char*)&number, sizeof(number));

        cout << number << endl;
    }

    resFile.close();

    return;
}

void initFifth()
{
    const int arrLength = 8;
    char chars[arrLength] = { 'a', 'b', '.', 'c', 'c', 'd', '.', 'd'};

    ofstream ofile;
    ofile.open("fifthTaskInput.txt", ios_base::binary | ios_base::trunc);

    for (int i = 0; i < arrLength; i++)
    {
        ofile.write(&(chars[i]), sizeof(chars[i]));
    }

    ofile.close();
}

void completeFifth()
{
    ifstream ifile;
    ifile.open("fifthTaskInput.txt", ios_base::binary);

    if (!ifile)
    {
        cout << "couldn`t open input file" << endl;
        return;
    }

    ifile.seekg(0, std::ios::end);
    streamsize size = ifile.tellg();
    ifile.seekg(0, std::ios::beg);

    char* buffer = new char[size];

    ifile.read(buffer, size);

    ifile.close();
    ifile.clear();

    string str(buffer);

    size_t lastDotPost = str.find_last_of('.');
    str.erase(lastDotPost, str.length());

    cout << str << endl;

    // rewrite file
    ofstream ofile;
    ofile.open("fifthTaskInput.txt", ios_base::binary | ios_base::trunc);

    if (!ofile)
    {
        cout << "couldn`t open input file" << endl;
        return;
    }

    ofile.write(str.c_str(), sizeof(str));
    ofile.close();
    

    // read result
    ifstream rfile;
    rfile.open("fifthTaskInput.txt", ios_base::binary);

    if (!rfile)
    {
        cout << "couldn`t open input file" << endl;
        return;
    }

    rfile.seekg(0, std::ios::end);
    streamsize size2 = rfile.tellg();
    rfile.seekg(0, std::ios::beg);

    char* buffer2 = new char[size2];

    rfile.read(buffer2, size2);

    rfile.close();

    cout << buffer2 << endl;
}

void completeIndividualTask4()
{
    vector<double> numbers;

    ifstream ifile;
    ifile.open("individualTaskInput.txt");

    double num;

    while (!ifile.eof())
    {
        ifile.read((char*)&num, sizeof(num));
        numbers.push_back(num);
    }

    ifile.close();
    ifile.clear();

    auto max = max_element(numbers.begin(), numbers.end());
    int maxItemIndex = distance(numbers.begin(), max);
    
    auto min = min_element(numbers.begin(), numbers.end());
    int minItemIndex = distance(numbers.begin(), min);

}

int main()
{
    //completeFirst();

    /*initSecond();
    completeSecond();*/

    /*initThird();
    completeThird();*/

    /*initFourth();
    completeFourth();*/

    /*initFifth();
    completeFifth();*/
}

void tmp()
{
    int numArr[3] = { 1, 2, 3 };

    ofstream f;
    f.open("text.txt", ios::binary);

    for (int i = 0; i < 3; i++)
    {
        f.write((char*)&(numArr[i]), sizeof(numArr[i]));
        f.seekp(ios::beg);
    }
    f.close();

    ifstream ifile;
    ifile.open("text.txt", ios::binary);

    int n = 0;
    while (ifile.read((char*)&(n), sizeof(n)))
    {
        cout << n << endl;
    }

    ifile.close();

    return;
}


