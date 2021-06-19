pipeline {
  agent any
  stages {
    stage('Yo') {
      steps {
        sh 'echo yo'
        timeout(time: 60) {
          sh 'echo hey'
        }

      }
    }

    stage('Sleep') {
      steps {
        sleep 10
      }
    }

    stage('Yoooo') {
      steps {
        sleep 10
      }
    }

  }
}