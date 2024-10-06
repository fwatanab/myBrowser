#ifndef NODE_H
#define NODE_H

#include <vector>
#include <memory>

class	Node {
	public:
		Node(const std::string& tagName);
		~Node();

		// 子ノードを追加
		void	addNode(std::shared_ptr<Node> child);

		// テキストを追加
		void	setContent(const std::string& text);

		// ノードのタグ名を取得
		std::string	getTagName() const;

		// テキストのコンテンツを取得
		std::string	getContent() const;

		// 子ノードを取得
		const std::vector<std::shared_ptr<Node>>&	getChildren() const;

	private:
		std::string	tagName; // タグ名
		std::string	content; // コンテント
		std::vector<std::shared_ptr<Node>>	children; // 子ノード
};

#endif
