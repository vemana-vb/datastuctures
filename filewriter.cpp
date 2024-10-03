#include "filewriter.h"

FileWriter::FileWriter()
{

}

void FileWriter::writeFile(string file, Solution &optimal, time_point<system_clock, nanoseconds> start, time_point<system_clock, nanoseconds> stop)
{
    std::ofstream oFile(file);
    if (!oFile.is_open()) {
        perror("file");
        return;
    }

    oFile << "Article\tType\tReporter\tCost\tClicks\n";
    for (const auto& ar : optimal.articles) {
        oFile << ar.getName() << "\t" << ar.getType() << "\t" << ar.getReporter() << "\t" << ar.getCost() << "\t" << ar.getClicks() << std::endl;
    }

    oFile << "Total Cost: " << optimal.totalCost() << std::endl;
    oFile << "Total Clicks: " << optimal.totalClicks() << std::endl;


    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    int hrs = duration.count() / 3600;
    int mins = (duration.count() % 3600) / 60;
    int secs = duration.count() % 60;

    oFile << "Computation Time: " << hrs << " hours, " << mins << " minutes, " << secs << " seconds." << std::endl;
    oFile.close();
}
