#include "PetModel.h"
#include "Validator.h"
#include <iostream>

PetModel::PetModel(): QAbstractTableModel(), undoActions(), redoActions()
{

}

PetModel::PetModel(Repository * repo)
{
	this->repo = repo;
}

PetModel::~PetModel()
{
	delete repo;
}

int PetModel::rowCount(const QModelIndex & parent) const
{
	return repo->getAll()->size();
}

int PetModel::columnCount(const QModelIndex &) const
{
	return 6;
}

QVariant PetModel::data(const QModelIndex & index, int role) const
{
	if (!index.isValid() || role != Qt::DisplayRole)
		return QVariant();

	auto v = repo->getAll();

	auto pet = (*v)[index.row()];

	switch (index.column())
	{
	case 0:
		return tr(pet.getBreed().c_str());
	case 1:
		return tr(pet.getName().c_str());
	case 2:
		return tr(std::to_string(pet.getName()).c_str());
	case 3:
		return tr(pet.getPhoto().c_str());
	default:
		return QVariant();
	}
	return QVariant();
}

QVariant PetModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
		return QVariant();
	if (orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:
			return tr("Breed: ");
		case 1:
			return tr("Name: ");
		case 2:
			return tr("Age: ");
		case 3:
			return tr("Photo: ");
		default:
			return QVariant();
		}
	}
	return QVariant();
}

void PetModel::undo()
{
	if (undoActions.empty())
		return;
	try
	{
		std::unique_ptr<Action> last = std::move(undoActions.back());
		last->undo();

		undoActions.pop_back();
		redoActions.push_back(std::move(last));
	}
	catch (RepositoryException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void PetModel::redo()
{
	if (redoActions.empty()) 
		return;

	try 
	{
		std::unique_ptr<Action> last = std::move(redoActions.back());
		last->redo();

		redoActions.pop_back();
		undoActions.push_back(std::move(last));
	}
	catch (RepositoryException& e) 
	{
		std::cout << e.what() << std::endl;
	}
}

bool PetModel::removeR(int row)
{
	Pet p = (*repo->getAll())[row];
	beginInsertRows(QModelIndex(), 0, 0);
	repo->deletePet(p.getName());
	std::unique_ptr<Action> action{ new RemoveAction{repo, p} };
	undoActions.push_back(std::move(action));
	redoActions.clear();
	endInsertRows();

	return true;
}

Qt::ItemFlags PetModel::flags(const QModelIndex & index) const
{
	if (index.column() == 5)
		return Qt::DisplayRole;
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;

}

bool PetModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (index.isValid() || role != Qt::EditRole)
		return false;

	int row = index.row();
	Pet p = (repo->getAll())[row];
	try
	{
		switch (index.column())
		{
		case 0:
		{
			std::string name = index.data().toString().toStdString;
			repo->updatePet(PetMaker::createPet(value.toString().toStdString(), p.getBreed(), std::to_string(p.getAge()), p.getPhoto()), name);
			Pet newP = Pet{ value.toString().toStdString(),p.getBreed(),p.getAge(),p.getPhoto };
			std::unique_ptr<Action> action{ new UpdateAction(repo,p,newP) };
			undoActions.push_back(std::move(action));
			redoActions.clear();
		}
				break;
		case 1:
		{

		}

		default:
			break;
		}
	}
}

