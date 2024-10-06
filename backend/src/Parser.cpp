#include <Parser.hpp>
#include <iostream>

Parser::Parser() : currentPosition(0) {}

Parser::~Parser() {}

std::shared_ptr<Node>	Parser::parseHTML(const std::string& html) {
	htmlData = html;
	currentPosition = 0;

	// ルートノードとしてhtmlを作成
	std::shared_ptr<Node>	rootNode = nullptr;
	std::shared_ptr<Node>	childNode = nullptr;

	while (currentPosition < html.size()) {
		if (html[currentPosition] == '<') {
			// タグを解析して子ノードを生成
			childNode = parseTag();
			if (childNode) {
				if (childNode->getTagName() == "html") {
					rootNode = childNode;
				}
				else if (rootNode) {
					// ルートノードの子として追加
					rootNode->addNode(childNode);
				}
				std::cout << childNode->getTagName() << std::endl;
			}
		}
		else {
			// テキストノードの処理
			std::string	textContent;
			while (currentPosition < html.size() && html[currentPosition] != '<') {
				textContent += html[currentPosition];
				currentPosition++;
			}
			// テキストをノードに追加
			if (!textContent.empty() && childNode) {
				childNode->setContent(textContent);
				std::cout << childNode->getContent() << std::endl;
			}
		}
	}

	return rootNode;
	
}

std::shared_ptr<Node>	Parser::parseTag() {
	// タグ名を格納する変数
	std::string	tagName;

	if (htmlData[currentPosition] == '<') {
		currentPosition++;

		// 終了タグをスキップ
		if (htmlData[currentPosition] == '/') {
			while (currentPosition < htmlData.size() && htmlData[currentPosition] != '>') {
				currentPosition++;
			}
			currentPosition++;
			return nullptr;
		}

		// タグ名の抽出ループ
		while (currentPosition < htmlData.size() && htmlData[currentPosition] != '>') {
			tagName+= htmlData[currentPosition];
			currentPosition++;
		}

		if (htmlData[currentPosition] == '>') {
			currentPosition++;
		}

		// Node オブジェクトを生成してタグ名を設定
		std::shared_ptr<Node>	newNode = std::make_shared<Node>(tagName);

		return newNode;
	}

	return nullptr;
}


// テストコード
//int	main() {
//	std::string html = "<html><body><p>Hello, World!</p></body></html>";
//
//	// パーサーを作成してHTMLをパース
//	Parser parser;
//	std::shared_ptr<Node> rootNode = parser.parseHTML(html);
//
//	// DOMツリーを再帰的に出力して確認
//	if (rootNode) {
//		std::cout << "DOM Tree:" << std::endl;
//		printDOM(rootNode); // DOMツリーを表示
//	} else {
//		std::cout << "Failed to parse HTML." << std::endl;
//	}
//
//	return 0;
//}
