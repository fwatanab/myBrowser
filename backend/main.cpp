#include <iostream>
#include "inc/Network.hpp"
#include <Parser.hpp>

//int	main() {
//	Network network;
//	std::string url = "https://www.example.com";
//	std::string pageContent = network.fetchPage(url);
//	if (!pageContent.empty()) {
//		std::cout << "Fetched page content: " << std::endl;
//		std::cout << pageContent << std::endl;
//	} else {
//		std::cerr << "Failed to fetch page content!" << std::endl;
//	}
//	return 0;
//}

void printDOM(const std::shared_ptr<Node>& node, int depth = 0) {
    // インデントを出力して階層を表現
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";  // インデントを追加
    }

    // ノードのタグ名を表示
    std::cout << "<" << node->getTagName() << ">";

    // コンテンツ（テキストノード）の表示
    if (!node->getContent().empty()) {
        std::cout << node->getContent();
    }

    std::cout << std::endl;

    // 子ノードがある場合、再帰的に表示
    const auto& children = node->getChildren();
    for (const auto& child : children) {
        printDOM(child, depth += 1);  // 子ノードを再帰的に表示（深さを1増やす）
    }

    // 閉じタグの表示
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";  // インデントを追加
    }
    std::cout << "</" << node->getTagName() << ">" << std::endl;
}

int	main() {
	std::string html = "<html><body><p>First paragraph</p><p>Second paragraph</p></body></html>";

	// パーサーを作成してHTMLをパース
	Parser parser;
	std::shared_ptr<Node> rootNode = parser.parseHTML(html);

	// DOMツリーを再帰的に出力して確認
	if (rootNode) {
		std::cout << "DOM Tree:" << std::endl;
		printDOM(rootNode); // DOMツリーを表示
	} else {
		std::cout << "Failed to parse HTML." << std::endl;
	}

	return 0;
}
