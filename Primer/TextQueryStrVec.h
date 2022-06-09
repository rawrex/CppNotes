#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <string>
#include "StrVec.h"
#include <iostream>
#include <memory>
#include <fstream>
#include <map>
#include <set>
#include <sstream>

struct QueryResult;
struct TextQuery {
friend QueryResult;
		using line_n = size_t;
		TextQuery(std::ifstream&);
		QueryResult query(const std::string&) const;
private:
		std::map<std::string, std::shared_ptr<std::set<line_n>>> wm;
		std::shared_ptr<StrVec> file;
};
TextQuery::TextQuery(std::ifstream &ifs) : file(new StrVec) {
		std::string line;
		while (getline(ifs, line)) {
				file->push_back(line);
				line_n n = file->size() - 1;
				std::string word;
				std::istringstream iss_line(line);
				while (iss_line >> word) {
						auto &lines = wm[word];
						if (!lines)
								lines.reset(new std::set<line_n>);
						lines->insert(n);
				}
		}
}

struct QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
	QueryResult(const std::string &w, std::shared_ptr<StrVec> f, std::shared_ptr<std::set<TextQuery::line_n>> n) :
	word(w), lines(n), file(f) {}
private:
	const std::string word;
	std::shared_ptr<std::set<TextQuery::line_n>> lines;
	std::shared_ptr<StrVec> file;
};

QueryResult TextQuery::query(const std::string &word) const {
		static std::shared_ptr<std::set<line_n>> nodata(new std::set<line_n>); // Not found any
		auto loc = wm.find(word);
		if (loc == wm.end())
			return QueryResult(word, file, nodata);
		return QueryResult(word, file, loc->second);
}

std::ostream& print(std::ostream &os, const QueryResult &qr) {
		for (auto num : *qr.lines)
				os << num + 1 << "\t" << *(qr.file->begin() + num) << std::endl;

		os << qr.word << " occurs on " << qr.lines->size() << " line(s)" << std::endl;
		return os; 
}

void word_lookup(const std::string &filename, const std::string &word) {
		std::ifstream ifs(filename);
		TextQuery tq(ifs);
		print(std::cout, tq.query(word)) << std::endl;
}

#endif
