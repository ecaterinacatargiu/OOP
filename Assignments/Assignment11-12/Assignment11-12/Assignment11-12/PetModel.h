#pragma once
#include <QObject>
#include <QAbstractTableModel>
#include "Repository.h"
#include <functional>
#include <vector>
#include "UndoRedo.h"
#include <memory>

class PetModel : public QAbstractTableModel 
{
private:
	Repository * repo;

public:
	std::vector<std::unique_ptr<Action>> undoActions;
	std::vector<std::unique_ptr<Action>> redoActions;

	PetModel();
	PetModel(Repository* repo);
	~PetModel();

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &) const;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

	void undo();
	void redo();

	//Repo
	Repository* getRepo() { return repo; };
	bool addR(Pet p);
	bool removeR(int row);

	Qt::ItemFlags flags(const QModelIndex & index) const override;

	bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;



};