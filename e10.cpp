class NoseHair {};
class Nose {
  ... private : NoseHair _noseHair;
};
class Head {
  ... private : Nose _nose;
};
class Human {
  ... private : Head _head;
};
class Man : public Human {};
class Woman : public Human {};
