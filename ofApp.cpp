#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);

	ofSetLineWidth(2);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofColor color;
	for (int base_deg = 0; base_deg < 360; base_deg += 3) {
		
		ofPushMatrix();
		ofRotateY(base_deg);

		color.setHsb(ofMap(base_deg, 0, 360, 0, 255), 139, 255);

		int deg_start = base_deg * 10 + ofGetFrameNum() * 3;
		for (int deg = deg_start; deg < deg_start + 90; deg += 1) {

			ofSetColor(color, ofMap(deg, deg_start, deg_start + 90, 0, 255));
			int param = ofMap(deg, 0, 360, 0, 100);
			auto location = glm::vec3(this->make_point(150, param), 230);
			auto next = glm::vec3(this->make_point(150, param + 1), 230);
							   
			ofDrawLine(glm::vec3(0, location.x, location.y + 300), glm::vec3(0, next.x, next.y + 300));
			
		}

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}