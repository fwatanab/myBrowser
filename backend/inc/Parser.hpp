#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <memory>
#include <Node.hpp>

class	Parser {
	public:
		Parser();
		~Parser();

		// HTMLをパースしてDOMツリーを生成
		std::shared_ptr<Node>	parseHTML(const std::string& html);
	private:
		// ヘルパー関数：単純なタグのパース
		std::shared_ptr<Node>	parseTag();
		// 現在のパース位置を保持
		size_t	currentPosition;
		// 現在のHTMLデータを保持
		std::string	htmlData;
};

#endif
