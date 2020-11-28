#include <iostream>

class Beverage {
public:
	std::string description = "Unknown Beverage";

public:
	virtual std::string getDescription() {
		return description;
	}
	virtual double cost() = 0;
};

class CondimentDecorator : public Beverage {
public:
	Beverage* beverage = nullptr;
public:
	virtual std::string getDescription() = 0;
};

class DarkRoast : public Beverage {
public:
	DarkRoast() {
		description = "Dark Roast Coffee";
	}
	double cost() override {
		return .99;
	}
};

class Decaf : public Beverage {
public:
	Decaf() {
		description = "Decaf Coffee";
	}

	double cost()  override {
		return 1.05;
	}

};

class Espresso : public Beverage {
public:
	Espresso() {
		description = "Espresso";
	}
	double cost() override {
		return 1.99;
	}
};

class HouseBlend : public Beverage {
public: HouseBlend() {
	description = "House Blend Coffee";

}
	  double cost() override {
		  return .89;
	  }
};

class Milk : public CondimentDecorator {
public: Milk(Beverage* beverage) {
	this->beverage = beverage;
}
	  std::string getDescription() override {
		  return beverage->getDescription() + ". Milk";
	  }

	  double cost() override {
		  return .10 + beverage->cost();
	  }

};

class Mocha : public CondimentDecorator {
public: Mocha(Beverage* beverage) {
	this->beverage = beverage;
}
	  std::string getDescription() override {
		  return beverage->getDescription() + ". Mocha";
	  }
	  double cost() override {
		  return .20 + beverage->cost();

	  }
};

class Soy : public CondimentDecorator {
public: Soy(Beverage* beverage) {
	this->beverage = beverage;
}
	  std::string getDescription() override {
		  return beverage->getDescription() + ". Soy";
	  }
	  double cost()  override {
		  return .15 + beverage->cost();
	  }
};

class Whip : public CondimentDecorator {
public: Whip(Beverage* beverage) {
	this->beverage = beverage;
}
	  std::string getDescription() override {
		  return beverage->getDescription() + ". Whip";
	  }
	  double cost() override {
		  return .10 + beverage->cost();
	  }
};


int main() {
	Beverage* beverage = new Espresso();
	std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;
	Beverage* beverage2 = new DarkRoast();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	std::cout << beverage2->getDescription() << " $" << beverage2->cost() << std::endl;
	Beverage* beverage3 = new HouseBlend();
	beverage3 = new Soy(beverage3);
	beverage3 = new Mocha(beverage3);
	beverage3 = new Whip(beverage3);
	std::cout << beverage3->getDescription() << " $" << beverage3->cost() << std::endl;

	return 0;
}


