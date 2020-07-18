#!/bin/sh

if [ "$CI" = "true" ] && [ "$TRAVIS" = "true" ]
then
  # You must add options either openssl will says :
  # *** WARNING : deprecated key derivation used.
  openssl aes-256-cbc -md sha512 -pbkdf2 -iter 100000 -k "$PASSWORD_OPENSSL" -out travis/ci/github_wiki_le_garrec_fr.key -in travis/ci/github_wiki_le_garrec_fr.key.enc -d
  # ssh-add says:
  # Permissions 0664 for 'travis/ci/github_wiki_le_garrec_fr.key' are too open.
  # It is required that your private key files are NOT accessible by others.
  chmod 600 travis/ci/github_wiki_le_garrec_fr.key
  ssh-add travis/ci/github_wiki_le_garrec_fr.key
fi
