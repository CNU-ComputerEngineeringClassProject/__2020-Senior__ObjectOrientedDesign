#include <iostream>

enum BeverageSize {
	TALL,
	GRANDE,
	VENTI,
};

class Beverage {
public:
	std::string description = "Unknown Beverage";
	BeverageSize beverageSize;
public:
	virtual std::string getDescription() {
		return description;
	}
	virtual double cost() = 0;

	virtual BeverageSize getSize() {
		return beverageSize;
	}

	void displayDescription() {
		std::cout << getDescription() << " : " << cost() << std::endl;
	}
};

class CondimentDecorator : public Beverage {
public:
	Beverage* beverage = nullptr;
public:
	virtual std::string getDescription() = 0;
};

class DarkRoast : public Beverage {
public:
	DarkRoast(BeverageSize beverageSize) {
		description = "Dark Roast Coffee";
		this->beverageSize = beverageSize;
	}
	double cost() override {
		if (getSize() == TALL)
			return .99;
		else if (getSize() == GRANDE)
			return 1.09;
		else if (getSize() == VENTI)
			return 1.19;

	}
};

class Decaf : public Beverage {
public:
	Decaf(BeverageSize beverageSize) {
		description = "Decaf Coffee";
		this->beverageSize = beverageSize;
	}

	double cost() override {
		if (getSize() == TALL)
			return 1.05;
		else if (getSize() == GRANDE)
			return 1.15;
		else if (getSize() == VENTI)
			return 1.25;
	}

};

class Espresso : public Beverage {
public:
	Espresso(BeverageSize beverageSize) {
		description = "Espresso";
		this->beverageSize = beverageSize;
	}
	double cost() override {
		if (getSize() == TALL)
			return 1.99;
		else if (getSize() == GRANDE)
			return 2.09;
		else if (getSize() == VENTI)
			return 2.19;
	}
};

class HouseBlend : public Beverage {
public: HouseBlend(BeverageSize beverageSize) {
	description = "House Blend Coffee";
	this->beverageSize = beverageSize;

}
	  double cost() override {
		  if (getSize() == TALL)
			  return .89;
		  else if (getSize() == GRANDE)
			  return .99;
		  else if (getSize() == VENTI)
			  return 1.09;
	  }
};

class Milk : public CondimentDecorator {
public: Milk(Beverage* beverage) {
	this->beverage = beverage;
}
	  std::string getDescription() override {
		  return beverage->getDescription() + ". Milk";
	  }
	  BeverageSize getSize() override {
		  return beverage->getSize();
	  }

	  double cost() override {
		  if (beverage->getSize() == TALL)
			  return beverage->cost() + 0.20;
		  else if (beverage->getSize() == GRANDE)
			  return beverage->cost() + 0.25;
		  else if (beverage->getSize() == VENTI)
			  return beverage->cost() + 0.30;
	  }

};

class Mocha : public CondimentDecorator {
public: Mocha(Beverage* beverage) {
	this->beverage = beverage;
}
	  std::string getDescription() override {
		  return beverage->getDescription() + ". Mocha";
	  }
	  BeverageSize getSize() override {
		  return beverage->getSize();
	  }
	  double cost()  override {
		  if (beverage->getSize() == TALL)
			  return beverage->cost() + 0.10;
		  else if (beverage->getSize() == GRANDE)
			  return beverage->cost() + 0.15;
		  else if (beverage->getSize() == VENTI)
			  return beverage->cost() + 0.20;

	  }
};

class Soy : public CondimentDecorator {
public: Soy(Beverage* beverage) {
	this->beverage = beverage;
}
	  std::string getDescription() override {
		  return beverage->getDescription() + ". Soy";
	  }
	  BeverageSize getSize() override {
		  return beverage->getSize();
	  }
	  double cost() override {
		  if (beverage->getSize() == TALL)
			  return beverage->cost() + 0.10;
		  else if (beverage->getSize() == GRANDE)
			  return beverage->cost() + 0.20;
		  else if (beverage->getSize() == VENTI)
			  return beverage->cost() + 0.30;
	  }
};

class Whip : public CondimentDecorator {
public: Whip(Beverage* beverage) {
	this->beverage = beverage;
}
	  std::string getDescription() override {
		  return beverage->getDescription() + ". Whip";
	  }
	  BeverageSize getSize()  override {
		  return beverage->getSize();
	  }
	  double cost()  override {
		  if (beverage->getSize() == TALL)
			  return beverage->cost() + 0.10;
		  else if (beverage->getSize() == GRANDE)
			  return beverage->cost() + 0.15;
		  else if (beverage->getSize() == VENTI)
			  return beverage->cost() + 0.20;
	  }
};


int main() {
	Beverage* beverage = new Espresso(TALL);
	beverage->displayDescription();
	Beverage* beverage2 = new DarkRoast(VENTI);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	beverage2->displayDescription();
	Beverage* beverage3 = new HouseBlend(GRANDE);
	beverage3 = new Soy(beverage3);
	beverage3 = new Mocha(beverage3);
	beverage3 = new Whip(beverage3);
	beverage3->displayDescription();

	return 0;
}


