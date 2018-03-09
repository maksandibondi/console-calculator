pipeline {
    agent any
    stages {
        stage('build') {
            steps {
				echo 'building..'
				bat 'build.cmd'
            }
        }
		
		stage('test') {
            steps {
                echo 'Testing..'
				bat 'test.cmd'
            }
        }
    }
}